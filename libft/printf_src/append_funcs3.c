/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_funcs3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:23:05 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 17:54:55 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int		check_flags(t_info *pt_list)
{
	if (pt_list->flagplus && pt_list->flagzero)
		return (1);
	return (0);
}

int		check_pr(t_info *pt_list)
{
	if (pt_list->prtotal == -1 || pt_list->prtotal == 0)
		return (1);
	return (0);
}

void	zero_plus(t_info *pt_list, char **s)
{
	char	*tmp;

	if (check_flags(pt_list) && istypeint(pt_list) && check_pr(pt_list))
	{
		tmp = ft_strjoin(pt_list->signstr, *s);
		free(*s);
		*s = tmp;
	}
}

void	zero_plus_float(t_info *pt_list, char **s)
{
	char	*tmp;

	if (check_flags(pt_list))
	{
		tmp = ft_strjoin(pt_list->signstr, *s);
		free(*s);
		*s = tmp;
	}
}
