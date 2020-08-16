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
#include "libftfprintf.h"

t_fbuffer		*initfbufferinfo(int fd, char buffer[])
{
	t_fbuffer *new;

	if (!(new = (t_fbuffer *)ft_memalloc(sizeof(t_fbuffer))))
		return (NULL);
	new->totallength = 0;
	ft_bzero(buffer, BUFF_SIZE);
	new->fd = fd;
	new->base_addr = buffer;
	return (new);
}

static int		empty_fbuffer(char buffer[], const char **format, \
				t_fbuffer *buff)
{
	int len;

	ft_strcat_fd(buffer, *format, buff);
	printbuffer_fd(buff);
	len = buff->totallength;
	free(buff);
	return (len);
}

int				ft_fprintf(int fd, const char *format, ...)
{
	va_list		arglist;
	t_fbuffer	*st_buffer;
	const char	*pos;
	char		buffer[BUFF_SIZE + 1];

	va_start(arglist, format);
	pos = (char *)format;
	st_buffer = initfbufferinfo(fd, buffer);
	while (*pos != '\0')
	{
		buffer[BUFF_SIZE] = '\0';
		if (*pos == '%')
		{
			ft_strncat_fd(buffer, format,
			(int)ft_strchr(format, '%') - (int)format, st_buffer);
			pos++;
			printconversion_fd(buffer, &pos, arglist, st_buffer);
			format = pos;
		}
		else
			pos++;
	}
	va_end(arglist);
	return (empty_fbuffer(buffer, &format, st_buffer));
}
