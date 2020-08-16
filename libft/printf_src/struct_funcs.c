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

t_info	*initstruct(t_buffer *buffer)
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
	new_info->buffer_base = buffer;
	new_info->signstr = "+";
	return (new_info);
}

int		isflag(const char c)
{
	if (c == '0' || c == ' ' || c == '-' || c == '+' || c == '#')
		return (1);
	return (0);
}

void	getflag(t_info *info, const char **format_position)
{
	if (isflag(**format_position))
	{
		if (**format_position == '0')
			info->flagzero = 1;
		else if (**format_position == '+')
			info->flagplus = 1;
		else if (**format_position == '#')
			info->flaghash = 1;
		else if (**format_position == ' ')
			info->flagspace = 1;
		else if (**format_position == '-')
		{
			info->flagminus = 1;
			info->flagzero = 0;
		}
		(*format_position)++;
		getflag(info, format_position);
	}
}

void	getwidthprecision(t_info *info, const char **format_position, \
		va_list arglist)
{
	if (**format_position == '*')
	{
		info->padtotal = va_arg(arglist, int);
		(*format_position)++;
	}
	else if (**format_position >= '1' && **format_position <= '9')
		info->padtotal = get_number(format_position);
	if (**format_position == '.')
	{
		(*format_position)++;
		if (**format_position >= '0' && **format_position <= '9')
		{
			if (**format_position == '0')
			{
				info->prtotal = 0;
				(*format_position)++;
			}
			if (**format_position >= '0' && **format_position <= '9')
				info->prtotal = get_number(format_position);
		}
		else
			info->prtotal = 0;
	}
}

t_info	*getstruct(const char **format_position, t_buffer *buffer, \
		va_list arglist)
{
	t_info *info;

	if (**format_position == '\0')
	{
		flushbuffer(buffer);
		exit(0);
	}
	info = initstruct(buffer);
	getflag(info, format_position);
	getwidthprecision(info, format_position, arglist);
	gettype(info, format_position);
	return (info);
}
