/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:27:04 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:45:13 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int		gettypecs(const char **format_position)
{
	if (**format_position == 'c')
		return (CHAR);
	else if (**format_position == 's')
		return (STRING);
	else if (**format_position == 'a')
		return (ABC);
	else if (**format_position == 'p')
		return (PTR);
	return (0);
}

int		gettypedigit(const char **format_position)
{
	if (**format_position == 'd' || **format_position == 'i')
		return (INT);
	else if (**format_position == 'u')
		return (UINT);
	else if (**format_position == 'o')
		return (OCTAL);
	else if (**format_position == 'f')
		return (FLOAT);
	return (0);
}

void	checklong(t_info *info, const char **format_position)
{
	(*format_position)++;
	if (**format_position == 'l')
	{
		info->is_long_long = 1;
		(*format_position)++;
	}
	else
		info->is_long = 1;
}

void	checkshort(t_info *info, const char **format_position)
{
	(*format_position)++;
	if (**format_position == 'h')
	{
		info->is_char = 1;
		(*format_position)++;
	}
	else
		info->is_short = 1;
}

int		checkconversion(t_info *info, const char **format_position)
{
	if (**format_position == 'c' || **format_position == 's'
	|| **format_position == 'p' || **format_position == 'a')
		info->type = gettypecs(format_position);
	else if (**format_position == 'd' || **format_position == 'i'
	|| **format_position == 'o' || **format_position == 'u'
	|| **format_position == 'f')
		info->type = gettypedigit(format_position);
	else if (**format_position == '%')
		info->type = PRCNT;
	else if (**format_position == 'x' || **format_position == 'X')
	{
		if (**format_position == 'x')
		{
			info->type = LOW_HEX;
			info->hextag = "0x";
		}
		else
		{
			info->type = UP_HEX;
			info->hextag = "0X";
		}
	}
	(*format_position)++;
	return (0);
}
