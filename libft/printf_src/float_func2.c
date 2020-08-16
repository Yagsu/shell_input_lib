/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:15:44 by juuttera          #+#    #+#             */
/*   Updated: 2020/01/17 15:14:50 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int					ft_round(char *str, int len)
{
	int index;

	if (len == 0)
		return (-1);
	index = len - 1;
	while (len-- && str[index] + 1 > '9' && str[index] != '.')
		str[index--] = '0';
	if (str[index] == '.')
		return (-1);
	str[index]++;
	len--;
	return (len);
}

void				get_fraction(double *dec, char *ind_str, int index)
{
	int fraction;

	*dec = *dec * 10;
	fraction = *dec;
	*dec -= fraction;
	ind_str[index] = fraction + 48;
}

void				get_fraction_long(long double *dec,
										char *ind_str,
										int index)
{
	int fraction;

	*dec = *dec * 10;
	fraction = *dec;
	*dec -= fraction;
	ind_str[index] = fraction + 48;
}

char				*ftoa(double db, char *str, int prec)
{
	int		iprec;
	double	dec;
	int		index;
	char	ind_str[4096];

	dec = db - (long int)db;
	if (dec < 0)
		dec *= -1;
	ft_memset(ind_str, 0, 4096);
	if (prec != -1 && prec != 0)
	{
		index = 1;
		ind_str[0] = '.';
		iprec = prec;
		while (iprec--)
			get_fraction(&dec, ind_str, index++);
	}
	if (dec * 10 >= 5)
		if (ft_round(ind_str, ft_strlen(ind_str)) < 0)
			db >= 0 ? db++ : db--;
	index = inttostr((long int)db, str, 0);
	if (prec > 0)
		ft_strcpy(&str[index], ind_str);
	return (str);
}

char				*ftoa_long(long double db, char *str, int prec)
{
	int			iprec;
	long double dec;
	int			index;
	char		ind_str[4096];

	dec = db - (long int)db;
	if (dec < 0)
		dec *= -1;
	ft_memset(ind_str, 0, 50);
	if (prec != -1 && prec != 0)
	{
		index = 1;
		ind_str[0] = '.';
		iprec = prec;
		while (iprec--)
			get_fraction_long(&dec, ind_str, index++);
	}
	if (dec * 10 >= 5)
		if (ft_round(ind_str, ft_strlen(ind_str)) < 0)
			db >= 0 ? db++ : db--;
	index = inttostr((long int)db, str, 0);
	if (prec > 0)
		ft_strcpy(&str[index], ind_str);
	return (str);
}
