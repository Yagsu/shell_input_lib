/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:26:56 by juuttera          #+#    #+#             */
/*   Updated: 2020/01/17 15:20:01 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			nb_size_uint(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size + 1);
}

char				*ft_itoa(int n)
{
	char			*ptr;
	unsigned int	nb;
	unsigned int	strsize;
	unsigned int	i;

	if (n >= 0)
		nb = (unsigned int)n;
	else
		nb = (unsigned int)(n * -1);
	strsize = (unsigned int)nb_size_uint(nb);
	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (strsize + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (ptr[i] = '-'))
		strsize++;
	i = strsize - 1;
	while (nb >= 10)
	{
		ptr[i--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	ptr[i] = (char)(nb % 10 + 48);
	ptr[strsize] = '\0';
	return (ptr);
}

char				*ft_itoa_uint(unsigned int n)
{
	char			*ptr;
	unsigned int	nb;
	unsigned int	strsize;
	unsigned int	i;

	nb = n;
	strsize = (unsigned int)nb_size_uint(nb);
	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (strsize + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (ptr[i] = '-'))
		strsize++;
	i = strsize - 1;
	while (nb >= 10)
	{
		ptr[i--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	ptr[i] = (char)(nb % 10 + 48);
	ptr[strsize] = '\0';
	return (ptr);
}
