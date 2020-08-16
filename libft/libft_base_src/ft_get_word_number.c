/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:59:07 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/27 12:41:33 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_word_number(char *s, char c)
{
	int		count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
		{
			s++;
			if (*s != c && *s)
				count++;
		}
		s++;
	}
	return (count + 1);
}
