/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:29:48 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/11 20:07:23 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa_base(int n, int base)
{
	char				*ptr;
	int					nb;
	unsigned int		strsize;
	int					i;

	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	strsize = nb_size_long_base(nb, base);
	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (strsize + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	i = strsize - 1;
	while (nb >= base)
	{
		ptr[i--] = (char)(nb % base + (nb % base > 9 ? 'a' - 10 : '0'));
		nb /= base;
	}
	ptr[i--] = (char)(nb % base + (nb % base > 9 ? 'a' - 10 : '0'));
	ptr[strsize] = '\0';
	return (ptr);
}

char				*ft_itoa_base_uint_long(unsigned long int n, int base)
{
	char					*ptr;
	unsigned long int		nb;
	unsigned long int		strsize;
	unsigned long int		i;

	nb = n;
	strsize = nb_size_long_base(nb, base);
	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (strsize + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	i = strsize - 1;
	while (nb >= (unsigned long int)base)
	{
		ptr[i--] = (char)(nb % base + (nb % base > 9 ? 'a' - 10 : '0'));
		nb /= base;
	}
	ptr[i--] = (char)(nb % base + (nb % base > 9 ? 'a' - 10 : '0'));
	ptr[strsize] = '\0';
	return (ptr);
}
