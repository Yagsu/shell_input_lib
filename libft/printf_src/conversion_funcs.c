/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:50:58 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:41:49 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

char	*parsestr(t_info *pt_list, va_list arglist)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(arglist, char *);
	if (tmp == NULL || tmp == 0)
		str = ft_strdup("(null)");
	else if (pt_list->prtotal == 0)
		str = ft_strdup("");
	else
		str = ft_strdup(tmp);
	return (str);
}

char	*parseint(t_info *pt_list, va_list arglist)
{
	char					*str;
	unsigned long long int	nb;
	long long int			i;

	if (pt_list->is_long || pt_list->is_long_long)
		i = getnumberlong(pt_list, arglist);
	else
		i = getnumber(pt_list, arglist);
	if (pt_list->flagplus && i >= 0)
		pt_list->signstr = "+";
	if (i < 0)
	{
		nb = i * -1;
		pt_list->flagplus = 1;
		pt_list->signstr = "-";
	}
	else
		nb = i;
	if (pt_list->prtotal == 0 && i == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base_long_low(nb, 10);
	return (str);
}

char	*handle_nullchar(t_info *pt_list)
{
	char	*str;

	str = getpadstr(pt_list, " ");
	flushbuffer(pt_list->buffer_base);
	if (!pt_list->flagminus)
		ft_putstr(str);
	ft_putchar(0);
	if (pt_list->flagminus)
		ft_putstr(str);
	pt_list->is_null = 0;
	return (NULL);
}

char	*parsechar(t_info *pt_list, va_list arglist)
{
	char	*chr;
	int		ch;

	ch = va_arg(arglist, int);
	chr = ft_strnew(1);
	if (ch == 0)
	{
		pt_list->is_null = 1;
		return (handle_nullchar(pt_list));
	}
	ft_memset(chr, ch, 1);
	return (chr);
}

char	*parseptr(t_info *pt_list, va_list arglist)
{
	char	*str;
	char	*tmp;

	pt_list->flaghash = 1;
	str = ft_itoa_base_long_low(va_arg(arglist, unsigned long int), 16);
	pt_list->hextag = "0x";
	if (pt_list->flagzero == 0 && pt_list->flaghash)
	{
		tmp = ft_strjoin(pt_list->hextag, str);
		free(str);
		str = tmp;
	}
	return (str);
}
