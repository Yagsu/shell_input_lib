/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:18:59 by juuttera          #+#    #+#             */
/*   Updated: 2020/07/17 18:49:00 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	if (!(ptr = (char *)malloc(sizeof(char) * size + 2)))
		return (NULL);
	i = 0;
	while (i <= size + 1)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
