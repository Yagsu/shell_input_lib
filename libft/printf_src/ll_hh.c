/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_hh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:24:55 by juuttera          #+#    #+#             */
/*   Updated: 2020/01/17 15:14:25 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int							getnumber(t_info *pt_list, va_list arglist)
{
	int nb;

	if (pt_list->is_short || pt_list->is_char)
	{
		if (pt_list->is_short)
			nb = (short int)va_arg(arglist, int);
		else
			nb = (char)va_arg(arglist, int);
	}
	else
		nb = va_arg(arglist, int);
	return (nb);
}

long long int				getnumberlong(t_info *pt_list, va_list arglist)
{
	long long int nb;

	if (pt_list->is_long_long)
		nb = va_arg(arglist, long long int);
	else
		nb = va_arg(arglist, long int);
	return (nb);
}

unsigned int				getnumberuint(t_info *pt_list, va_list arglist)
{
	unsigned int nb;

	if (pt_list->is_short || pt_list->is_char)
	{
		if (pt_list->is_short)
			nb = (short unsigned int)va_arg(arglist, unsigned int);
		else
			nb = (unsigned char)va_arg(arglist, unsigned int);
	}
	else
		nb = va_arg(arglist, int);
	return (nb);
}

long long unsigned int		getnblonguint(t_info *pt_list, va_list arglist)
{
	long long unsigned int nb;

	if (pt_list->is_long_long)
		nb = va_arg(arglist, long long unsigned int);
	else
		nb = va_arg(arglist, long unsigned int);
	return (nb);
}
