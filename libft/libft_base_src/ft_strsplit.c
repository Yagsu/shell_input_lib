/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:03 by juuttera          #+#    #+#             */
/*   Updated: 2020/07/09 01:26:35 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_string_length(char *s, char c)
{
	int		count;

	count = 0;
	while (*s != c && *s)
	{
		count++;
		s++;
	}
	return (count);
}

static char		*get_segment(const char **s, char c)
{
	int		i;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * \
	(get_string_length((char *)(*s), c) + 1))))
		return (NULL);
	i = 0;
	while (*(*s) != c && *(*s))
	{
		res[i] = (char)*(*s);
		(*s)++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		index;
	int		j;

	index = 0;
	if (!s || (!(str = (char **)malloc(sizeof(char *) * \
	(ft_get_word_number((char *)s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		j = 0;
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			str[index] = get_segment(&s, c);
			index++;
		}
	}
	str[index] = NULL;
	return (str);
}
