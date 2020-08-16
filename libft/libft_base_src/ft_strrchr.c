/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:44:07 by juuttera          #+#    #+#             */
/*   Updated: 2019/10/21 15:04:00 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (s[i] != c && i > 0)
	{
		--i;
	}
	if (i == 0 && s[i] != c)
		return (NULL);
	else if (s[i] == c)
		return ((char *)&s[i]);
	else
		return (NULL);
}
