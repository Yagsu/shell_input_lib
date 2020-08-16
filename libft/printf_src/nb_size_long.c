/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_size_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:10:13 by juuttera          #+#    #+#             */
/*   Updated: 2020/01/17 15:14:20 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int		nb_size_long(long long int nb)
{
	unsigned int			size;
	unsigned long long int	nbr;

	nbr = nb * -1;
	size = 0;
	if (nb < 0)
		size = size + 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		++size;
	}
	return (size + 1);
}
