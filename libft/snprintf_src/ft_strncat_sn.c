/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_sn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:38:37 by juuttera          #+#    #+#             */
/*   Updated: 2020/07/09 01:19:00 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "libftsnprintf.h"

void		flushbuffer_sn(t_snbuffer *buffer)
{
	ft_append(buffer);
	ft_bzero(buffer->base_addr, BUFF_SIZE);
	buffer->curlength = 0;
}

void		printbuffer_sn(t_snbuffer *buffer)
{
	ft_append(buffer);
	ft_strclr(buffer->base_addr);
	buffer->curlength = 0;
}

char		*ft_strncat_sn(char *dest, const char *src, \
			size_t n, t_snbuffer *buffer)
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
			flushbuffer_sn(buffer);
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

char		*ft_strcat_sn(char *dest, const char *src, t_snbuffer *buffer)
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
			flushbuffer_sn(buffer);
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
