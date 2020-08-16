/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:32:32 by juuttera          #+#    #+#             */
/*   Updated: 2020/07/19 01:35:06 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "libftsnprintf.h"

t_snbuffer		*initsnbufferinfo(char **buf, char buffer[])
{
	t_snbuffer *new;

	if (!(new = (t_snbuffer *)ft_memalloc(sizeof(t_snbuffer))))
		return (NULL);
	new->totallength = 0;
	ft_bzero(buffer, BUFF_SIZE);
	new->res_buf = buf;
	(*new->res_buf) = (char *)malloc(sizeof(char) * 2);
	(*new->res_buf)[0] = '\0';
	new->res_len = 0;
	new->base_addr = buffer;
	return (new);
}

static int		empty_snbuffer(char buffer[], const char **format, \
				t_snbuffer *buff)
{
	int len;

	ft_strcat_sn(buffer, *format, buff);
	printbuffer_sn(buff);
	len = buff->totallength;
	free(buff);
	return (len);
}

int				ft_snprintf(char **buf, const char *format, ...)
{
	va_list		arglist;
	t_snbuffer	*st_buffer;
	const char	*pos;
	char		buffer[BUFF_SIZE + 1];

	va_start(arglist, format);
	pos = (char *)format;
	st_buffer = initsnbufferinfo(buf, buffer);
	while (*pos != '\0')
	{
		buffer[BUFF_SIZE] = '\0';
		if (*pos == '%')
		{
			ft_strncat_sn(buffer, format,
			(int)ft_strchr(format, '%') - (int)format, st_buffer);
			pos++;
			printconversion_sn(buffer, &pos, arglist, st_buffer);
			format = pos;
		}
		else
			pos++;
	}
	va_end(arglist);
	return (empty_snbuffer(buffer, &format, st_buffer));
}
