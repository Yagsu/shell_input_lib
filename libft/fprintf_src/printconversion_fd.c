/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 20:27:34 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:43:53 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "libftfprintf.h"

void		printconversion_fd(char buffer[], const char **format_position,
			va_list arglist, t_fbuffer *list_buffer)
{
	t_info	*info;
	char	*done;

	if (!(info = getstruct_fd(format_position, list_buffer, arglist)))
		exit(0);
	if (!info->type)
	{
		invalid_type_fd(format_position, buffer, list_buffer);
		return ;
	}
	done = appendresult(info, arglist);
	if (!(done))
		return ;
	ft_strncat_fd(buffer, done, ft_strlen(done), list_buffer);
	free_n(2, done, info);
}
