/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_funcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:50:16 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 17:54:28 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	hex_width(t_info *pt_list, char **s)
{
	char	*tmp;

	if (pt_list->prtotal != -1 && ((int)ft_strlen(*s) < pt_list->prtotal))
	{
		tmp = ft_strjoin(getintwidth(pt_list, *s), *s);
		free(*s);
		*s = tmp;
	}
}

int		pr_zero(t_info *pt_list, char *s)
{
	if (pt_list->flagzero && pt_list->prtotal <= (int32_t)ft_strlen(s) &&
	pt_list->prtotal > 0)
		return (1);
	return (0);
}

int		plus_nzero(t_info *pt_list, char *s)
{
	if (pt_list->flagplus && (pt_list->flagzero == 0 || pr_zero(pt_list, s)))
		return (1);
	return (0);
}

void	plus_flag(t_info *pt_list, char **s)
{
	char	*tmp;

	if (istypeint(pt_list) && ((!ft_strcmp(pt_list->signstr, "-") &&
	!pt_list->flagplus) || plus_nzero(pt_list, *s)))
	{
		tmp = ft_strjoin(pt_list->signstr, *s);
		free(*s);
		*s = tmp;
	}
}

void	plus_flag_float(t_info *pt_list, char **s)
{
	char	*tmp;

	if ((pt_list->flagplus ||
	!ft_strcmp(pt_list->signstr, "-")) && !pt_list->flagzero)
	{
		tmp = ft_strjoin(pt_list->signstr, *s);
		free(*s);
		*s = tmp;
	}
}
