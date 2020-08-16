/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:38:37 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:42:44 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "libftfprintf.h"

void		flushbuffer_fd(t_fbuffer *buffer)
{
	ft_putstr_fd(buffer->base_addr, buffer->fd);
	ft_bzero(buffer->base_addr, BUFF_SIZE);
	buffer->curlength = 0;
}

void		printbuffer_fd(t_fbuffer *buffer)
{
	ft_putstr_fd(buffer->base_addr, buffer->fd);
	ft_strclr(buffer->base_addr);
	buffer->curlength = 0;
}

char		*ft_strncat_fd(char *dest, const char *src, \
			size_t n, t_fbuffer *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < n)
	{
		if (buffer->curlength == BUFF_SIZE)
		{
			flushbuffer_fd(buffer);
			i = 0;
		}
		if (buffer->curlength < BUFF_SIZE)
		{
			(buffer->curlength)++;
			(buffer->totallength)++;
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strcat_fd(char *dest, const char *src, t_fbuffer *buffer)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		if (buffer->curlength == BUFF_SIZE)
		{
			flushbuffer_fd(buffer);
			i = 0;
		}
		if (buffer->curlength < BUFF_SIZE)
		{
			(buffer->curlength)++;
			(buffer->totallength)++;
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
