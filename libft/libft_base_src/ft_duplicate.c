/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:11:26 by juuttera          #+#    #+#             */
/*   Updated: 2019/10/24 15:15:05 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_duplicate_content(void const *content, size_t content_size)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	void			*new;

	if (!(new = ft_memalloc(content_size)))
		return (NULL);
	ptr1 = (unsigned char *)content;
	ptr2 = (unsigned char *)new;
	while (*ptr1)
		*(ptr2++) = *(ptr1++);
	return (new);
}
