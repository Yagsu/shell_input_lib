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

void	flushbuffer(t_buffer *buffer)
{
	ft_putstr(buffer->base_addr);
	ft_bzero(buffer->base_addr, BUFF_SIZE);
	buffer->curlength = 0;
}

void	printbuffer(t_buffer *buffer)
{
	ft_putstr(buffer->base_addr);
	ft_strclr(buffer->base_addr);
	buffer->curlength = 0;
}

char	*ft_strncat_p(char *dest, const char *src, size_t n, t_buffer *buffer)
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
			flushbuffer(buffer);
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

char	*ft_strcat_p(char *dest, const char *src, t_buffer *buffer)
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
			flushbuffer(buffer);
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

char	*ft_strjoin_p(char const *s1, char *s2)
{
	char	*ptr;
	int		index[2];

	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = (char *)malloc(sizeof(char) * \
		(ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1)))
		return (NULL);
	ft_bzero(index, 2);
	while (s1[index[0]] != '\0')
	{
		ptr[index[1]] = s1[index[0]];
		index[1]++;
		index[0]++;
	}
	index[0] = 0;
	while (s2[index[0]] != '\0')
	{
		ptr[index[1]] = s2[index[0]];
		index[1]++;
		index[0]++;
	}
	ptr[index[1]] = '\0';
	free(s2);
	return (ptr);
}
