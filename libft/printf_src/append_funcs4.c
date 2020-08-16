/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_funcs4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:44:41 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 17:55:47 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int			check_strlen(t_info *pt_list, char *s)
{
	if (pt_list->padtotal >= (int32_t)(ft_strlen(s) + 2))
		return (1);
	return (0);
}

int			check_space_fl(t_info *pt_list)
{
	if (!pt_list->flagplus && !is_hex(pt_list) &&
		ft_strcmp(pt_list->signstr, "-"))
		return (1);
	return (0);
}

void		handle_hextag(t_info *pt_list, char **s)
{
	char	*tmp;

	if (pt_list->flaghash && pt_list->flagzero && check_strlen(pt_list, *s))
	{
		tmp = ft_strjoin(pt_list->hextag, *s);
		free(*s);
		*s = tmp;
	}
}

void		pad_space(t_info *pt_list, char **s)
{
	char	*tmp;

	if (pt_list->flagspace && check_space_fl(pt_list))
	{
		tmp = ft_strjoin(" ", *s);
		free(*s);
		*s = tmp;
	}
}

char		*get_hex_str(t_info *pt_list, va_list arglist)
{
	char	*str;

	if (pt_list->type == LOW_HEX)
	{
		if (pt_list->is_long_long || pt_list->is_long)
			str = ft_itoa_base_long_low(getnblonguint(pt_list, arglist), 16);
		else
			str = ft_itoa_base_low(getnumberuint(pt_list, arglist), 16);
	}
	else
	{
		if (pt_list->is_long_long || pt_list->is_long)
			str = ft_itoa_base_long_up(getnblonguint(pt_list, arglist), 16);
		else
			str = ft_itoa_base_up(getnumberuint(pt_list, arglist), 16);
	}
	return (str);
}
