/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:59:24 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/11 20:07:14 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				nb_size_long_base(unsigned long int nb, int base)
{
	unsigned int	size;

	size = 0;
	while (nb >= (unsigned long int)base)
	{
		nb /= base;
		++size;
	}
	return (size + 1);
}

char			*ft_itoa_base_long_up(unsigned long int n, int base)
{
	char				*ptr;
	unsigned long int	nb;
	unsigned long int	strsize;
	unsigned long int	i;

	nb = n;
	strsize = nb_size_long_base(nb, base);
	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (strsize + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	i = strsize - 1;
	while (nb >= (unsigned long int)base)
	{
		ptr[i--] = (char)(nb % base + (nb % base > 9 ? 'A' - 10 : '0'));
		nb /= base;
	}
	ptr[i--] = (char)(nb % base + (nb % base > 9 ? 'A' - 10 : '0'));
	ptr[strsize] = '\0';
	return (ptr);
}

char			*ft_itoa_base_up(unsigned int n, int base)
{
	char			*ptr;
	unsigned int	nb;
	unsigned int	strsize;
	unsigned int	i;

	nb = n;
	strsize = (unsigned int)nb_size_long_base(nb, base);
	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (strsize + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	i = strsize - 1;
	while (nb >= (unsigned int)base)
	{
		ptr[i--] = (char)(nb % base + (nb % base > 9 ? 'A' - 10 : '0'));
		nb /= base;
	}
	ptr[i--] = (char)(nb % base + (nb % base > 9 ? 'A' - 10 : '0'));
	ptr[strsize] = '\0';
	return (ptr);
}

char			*ft_itoa_base_low(unsigned int n, int base)
{
	char			*ptr;
	unsigned int	nb;
	unsigned int	strsize;
	unsigned int	i;

	nb = n;
	strsize = (unsigned int)nb_size_long_base(nb, base);
	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (strsize + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	i = strsize - 1;
	while (nb >= (unsigned int)base)
	{
		ptr[i--] = (char)(nb % base + (nb % base > 9 ? 'a' - 10 : '0'));
		nb /= base;
	}
	ptr[i--] = (char)(nb % base + (nb % base > 9 ? 'a' - 10 : '0'));
	ptr[strsize] = '\0';
	return (ptr);
}

char			*ft_itoa_base_long_low(unsigned long int n, int base)
{
	char				*ptr;
	unsigned long int	nb;
	unsigned long int	strsize;
	unsigned long int	i;

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
