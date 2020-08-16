/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_funcs_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:04:31 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 17:58:08 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

char		*getintwidth(t_info *pt_list, char *resstr)
{
	char	*done;
	int		zeropad;

	zeropad = pt_list->prtotal - ft_strlen(resstr);
	done = ft_strnew(zeropad);
	if (zeropad > 0)
		ft_memset(done, '0', zeropad);
	return (done);
}

char		*parsehex(t_info *pt_list, va_list arglist)
{
	char	*str;

	str = get_hex_str(pt_list, arglist);
	if (pt_list->prtotal < pt_list->padtotal &&
	pt_list->type != FLOAT && pt_list->prtotal != -1)
		pt_list->flagzero = 0;
	if (!(ft_strcmp(str, "0")))
	{
		if (pt_list->prtotal == 0)
		{
			free(str);
			str = ft_strnew(0);
		}
		pt_list->is_zero = 1;
	}
	return (str);
}

char		*parseuint(t_info *pt_list, va_list arglist)
{
	char				*str;
	unsigned long int	uint;

	if (pt_list->is_long_long || pt_list->is_long)
		uint = getnblonguint(pt_list, arglist);
	else
		uint = getnumberuint(pt_list, arglist);
	pt_list->signstr = "+";
	if (pt_list->prtotal == 0 && uint == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base_uint_long(uint, 10);
	return (str);
}

char		*parseoctal(t_info *pt_list, va_list arglist)
{
	char									*str;
	char									*tmp;
	long long unsigned int					i;

	if (pt_list->is_long || pt_list->is_long_long)
		i = getnblonguint(pt_list, arglist);
	else
		i = getnumberuint(pt_list, arglist);
	str = ft_itoa_base_uint_long(i, 8);
	pt_list->signstr = "+";
	if (i == 0 && pt_list->prtotal == 0 && pt_list->flaghash == 0)
	{
		free(str);
		str = ft_strnew(0);
	}
	if (pt_list->flaghash && i)
	{
		tmp = ft_strjoin("0", str);
		free(str);
		str = tmp;
	}
	return (str);
}

char		*parseabc(t_info *pt_list, va_list arglist)
{
	char	*str;
	char	*str2;
	int		pr;

	pr = pt_list->prtotal;
	str2 = va_arg(arglist, char *);
	str = ft_strjoin(str2, "ABC");
	return (str);
}
