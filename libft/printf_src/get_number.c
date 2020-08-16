/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:50:36 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:42:50 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int		get_number(char const **format)
{
	char	*tmp;
	int		nblength;
	int		padding;
	int		i;

	i = 0;
	padding = 0;
	nblength = 0;
	tmp = ft_strdup(&(**format));
	while (ft_isdigit(tmp[i++]))
		nblength++;
	free(tmp);
	tmp = ft_strnew(nblength);
	i = 0;
	while (ft_isdigit(**format))
	{
		tmp[i++] = **format;
		(*format)++;
	}
	padding = ft_atoi(tmp);
	free(tmp);
	return (padding);
}
