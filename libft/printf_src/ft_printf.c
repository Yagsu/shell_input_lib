/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:32:32 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:42:07 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

t_buffer	*initbufferinfo(char buffer[])
{
	t_buffer *new;

	if (!(new = (t_buffer *)ft_memalloc(sizeof(t_buffer))))
		return (NULL);
	new->totallength = 0;
	ft_bzero(buffer, BUFF_SIZE);
	new->base_addr = buffer;
	return (new);
}

int			empty_buffer(char buffer[], const char **format, t_buffer *buff)
{
	int len;

	ft_strcat_p(buffer, *format, buff);
	printbuffer(buff);
	len = buff->totallength;
	free(buff);
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list		arglist;
	t_buffer	*st_buffer;
	const char	*pos;
	char		buffer[BUFF_SIZE + 1];

	va_start(arglist, format);
	pos = (char *)format;
	st_buffer = initbufferinfo(buffer);
	while (*pos != '\0')
	{
		buffer[BUFF_SIZE] = '\0';
		if (*pos == '%')
		{
			ft_strncat_p(buffer, format,
			(int)ft_strchr(format, '%') - (int)format, st_buffer);
			pos++;
			printconversion(buffer, &pos, arglist, st_buffer);
			format = pos;
		}
		else
			pos++;
	}
	va_end(arglist);
	return (empty_buffer(buffer, &format, st_buffer));
}
