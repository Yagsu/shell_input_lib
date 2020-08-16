/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printconversion_sn.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 20:27:34 by juuttera          #+#    #+#             */
/*   Updated: 2020/07/09 00:42:07 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "libftsnprintf.h"

void		printconversion_sn(char buffer[], const char **format_position,
			va_list arglist, t_snbuffer *list_buffer)
{
	t_info	*info;
	char	*done;

	if (!(info = getstruct_sn(format_position, list_buffer, arglist)))
		exit(0);
	if (!info->type)
	{
		invalid_type_sn(format_position, buffer, list_buffer);
		return ;
	}
	done = appendresult(info, arglist);
	if (!(done))
		return ;
	ft_strncat_sn(buffer, done, ft_strlen(done), list_buffer);
	free_n(2, done, info);
}
