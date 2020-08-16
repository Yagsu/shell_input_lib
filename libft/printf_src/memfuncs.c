/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memfuncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:34:58 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:46:11 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	free_n(int n, ...)
{
	va_list arglist;
	void	*ptr;

	va_start(arglist, n);
	while (n--)
	{
		ptr = va_arg(arglist, void *);
		free(ptr);
		ptr = NULL;
	}
	va_end(arglist);
}

int		check_type(t_info *pt_list)
{
	if (pt_list->flagplus && istypeint(pt_list))
		return (1);
	return (0);
}

int		check_prec(t_info *pt_list)
{
	if (pt_list->prtotal == -1 || pt_list->prtotal == 0)
		return (1);
	return (0);
}

int		getactualpad(t_info *pt_list, char *str)
{
	int	pad;

	pad = pt_list->padtotal - ft_strlen(str);
	if (pt_list->flaghash)
		if ((pt_list->type == LOW_HEX || pt_list->type == UP_HEX) && \
		pt_list->flagzero && ft_strcmp(str, "0"))
			pad -= 2;
	if (pt_list->flagspace && pt_list->flagplus == 0 && \
	(pt_list->type != LOW_HEX && pt_list->type != UP_HEX))
		pad -= 1;
	if (pt_list->type == FLOAT)
	{
		if (pt_list->flagplus && pt_list->flagzero)
			pad -= 1;
	}
	else
	{
		if (check_type(pt_list) && check_prec(pt_list) && pt_list->flagzero)
			pad -= 1;
	}
	return (pad);
}
