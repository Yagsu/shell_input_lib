/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:38:10 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:43:30 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int		is_notsc(t_info *pt_list)
{
	if (pt_list->type == LOW_HEX || pt_list->type == UP_HEX ||
	pt_list->type == PRCNT || pt_list->type == OCTAL ||
	istypeint(pt_list))
		return (pt_list->type);
	return (0);
}

int		is_hex(t_info *pt_list)
{
	if (pt_list->type == LOW_HEX || pt_list->type == UP_HEX)
		return (pt_list->type);
	return (0);
}
