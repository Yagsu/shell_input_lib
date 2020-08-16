/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:26:52 by juuttera          #+#    #+#             */
/*   Updated: 2020/01/17 15:14:53 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void				reverse_str(char *str, int len)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

int					inttostr(long int x, char *str, int d)
{
	int i;
	int neg;

	neg = 0;
	i = 0;
	if (x < 0)
		x *= -1;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i <= d)
	{
		str[i++] = '0';
	}
	reverse_str(str, ft_strlen(str));
	str[i] = '\0';
	return (i);
}

int					ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

long long int		ft_pow(int nb, int pow)
{
	int res;

	res = nb;
	if (nb != 0 && pow == 0)
		return (1);
	while (ft_abs(pow) != 1)
	{
		res *= nb;
		pow--;
	}
	return (res);
}
