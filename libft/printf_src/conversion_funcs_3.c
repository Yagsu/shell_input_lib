/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_funcs_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:27:29 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:41:12 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void		ft_strjoin_c(char **str, char *str2)
{
	char		*tmp;

	tmp = ft_strjoin(*str, str2);
	free(*str);
	*str = tmp;
}

char		*parseprcnt(t_info *pt_list, va_list arglist)
{
	char	*str;
	int		pt;
	va_list a;

	va_copy(a, arglist);
	pt = pt_list->prtotal;
	va_end(a);
	str = ft_strdup("%");
	return (str);
}

char		*parsefloat_l(t_info *pt_list, va_list arglist)
{
	long double ldb;
	char		*str;
	int			nb_sz;

	ldb = va_arg(arglist, long double);
	if (ldb < 0)
	{
		pt_list->signstr = "-";
		pt_list->flagplus = 1;
	}
	else
		pt_list->signstr = "+";
	nb_sz = nb_size_long((long long int)ldb);
	str = (char *)ft_memalloc(nb_sz + \
	(pt_list->prtotal >= 0 ? pt_list->prtotal + 1 : 0));
	ftoa_long(ldb, str, pt_list->prtotal);
	return (str);
}

char		*parsefloat(t_info *pt_list, va_list arglist)
{
	char		*str;
	double		db;
	int			nb_sz;

	if (pt_list->prtotal == -1)
		pt_list->prtotal = 6;
	if (pt_list->is_long_float)
		return (parsefloat_l(pt_list, arglist));
	db = va_arg(arglist, double);
	nb_sz = nb_size_long((long long int)db);
	str = (char *)ft_memalloc(nb_sz + \
	(pt_list->prtotal >= 0 ? pt_list->prtotal + 1 : 0));
	ftoa(db, str, pt_list->prtotal);
	if (db < 0)
	{
		pt_list->signstr = "-";
		pt_list->flagplus = 1;
	}
	else
		pt_list->signstr = "+";
	if (pt_list->prtotal == 0 && pt_list->flaghash)
		ft_strjoin_c(&str, ".");
	return (str);
}
