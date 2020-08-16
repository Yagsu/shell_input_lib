/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:56:45 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:44:50 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "libftfprintf.h"

t_info	*initstruct_fd(t_fbuffer *buffer)
{
	t_info *new_info;

	if (!(new_info = (t_info *)malloc(sizeof(*new_info))))
		return (NULL);
	new_info->flagzero = 0;
	new_info->flagminus = 0;
	new_info->flagplus = 0;
	new_info->flaghash = 0;
	new_info->flagspace = 0;
	new_info->padtotal = 0;
	new_info->fieldwidth = 0;
	new_info->prtotal = -1;
	new_info->is_long = 0;
	new_info->is_long_long = 0;
	new_info->is_long_float = 0;
	new_info->is_short = 0;
	new_info->is_char = 0;
	new_info->is_null = 0;
	new_info->is_zero = 0;
	new_info->type = 0;
	new_info->buffer_base = (t_buffer *)buffer;
	new_info->signstr = "+";
	return (new_info);
}

t_info	*getstruct_fd(const char **format_position, t_fbuffer *buffer, \
		va_list arglist)
{
	t_info *info;

	if (**format_position == '\0')
	{
		flushbuffer_fd(buffer);
		exit(0);
	}
	info = initstruct_fd(buffer);
	getflag(info, format_position);
	getwidthprecision(info, format_position, arglist);
	gettype(info, format_position);
	return (info);
}
