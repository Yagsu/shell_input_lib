/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:16:35 by juuttera          #+#    #+#             */
/*   Updated: 2019/10/25 16:26:07 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_spaces_before(char *str)
{
	int	spaces;
	int	i;

	i = 0;
	spaces = 0;
	if (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			spaces++;
			i++;
		}
	}
	return (spaces);
}

static int		get_spaces_after(char *str)
{
	int spaces;
	int	i;

	spaces = 0;
	i = ft_strlen(str) - 1;
	if (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			++spaces;
			i--;
		}
	}
	return (spaces);
}

char			*ft_strtrim(char const *s)
{
	char	*ptr;
	int		spaces[2];
	int		i;
	int		length;

	if (!s)
		return (NULL);
	spaces[1] = get_spaces_after((char *)s);
	spaces[0] = get_spaces_before((char *)s);
	if (spaces[0] == 0 && spaces[1] == 0)
		return (ft_strdup((char *)s));
	if ((length = (ft_strlen((char *)s)) - (spaces[1] + spaces[0])) < 0)
		length = 0;
	if (!(ptr = (char *)malloc(length + 1)))
		return (NULL);
	i = 0;
	while (length)
	{
		ptr[i] = s[spaces[0] + i];
		i++;
		--length;
	}
	ptr[i] = '\0';
	return (ptr);
}
