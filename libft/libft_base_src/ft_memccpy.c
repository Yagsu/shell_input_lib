/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:24:36 by juuttera          #+#    #+#             */
/*   Updated: 2019/10/23 16:42:27 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptrd;
	unsigned char		*ptrs;

	ptrs = (unsigned char *)src;
	ptrd = (unsigned char *)dst;
	i = 0;
	while (i < n && (i == 0 || ptrs[i - 1] != (unsigned char)c))
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	if (i > 0 && ptrs[i - 1] == (unsigned char)c)
		return (dst + i);
	else
		return (NULL);
}
