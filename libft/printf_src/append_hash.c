/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:36:59 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 17:56:13 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int		zero_pad(t_info *pt_list, char *s)
{
	if (pt_list->flagzero)
	{
		if (pt_list->prtotal >= 0 && pt_list->prtotal <= (int32_t)ft_strlen(s))
			return (1);
		else if (pt_list->padtotal && pt_list->padtotal <=
		(int32_t)ft_strlen(s))
			return (1);
	}
	return (0);
}

int		check_hash(t_info *pt_list)
{
	if (!pt_list->flagzero && pt_list->flaghash)
		return (1);
	return (0);
}

void	append_hextag(t_info *pt_list, char **s)
{
	char *tmp;

	if (!pt_list->is_zero && pt_list->flaghash)
	{
		if (zero_pad(pt_list, *s) || check_hash(pt_list))
		{
			tmp = ft_strjoin(pt_list->hextag, *s);
			free(*s);
			*s = tmp;
		}
	}
}
