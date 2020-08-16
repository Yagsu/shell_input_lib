/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:25:54 by jesse             #+#    #+#             */
/*   Updated: 2020/07/16 22:52:21 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		is_last_node(t_trie_node *root)
{
	int i;

	i = 0;
	while (i < ALPHABET_SIZE)
	{
		if (root->children[i])
			return (0);
		i++;
	}
	return (1);
}

char	*string_from_char(int i)
{
	char *res;

	res = (char *)malloc(sizeof(char) * 2);
	if (i < 26)
		res[0] = (char)(65 + i);
	else if (i >= 26 && i < 52)
		res[0] = (char)(97 + (i - 26));
	else if (i == 52)
		res[0] = '_';
	else if (i == 53)
		res[0] = '.';
	else if (i >= 54 && i <= 63)
		res[0] = (char)(48 + (i - 54));
	res[1] = '\0';
	return (res);
}

int		char_to_index(char c)
{
	if (c >= 'a' && c <= 'z')
		return ((c - (int)'a') + 26);
	if (c >= 'A' && c <= 'Z')
		return (c - (int)'A');
	if (c == '_')
		return (52);
	if (c == '.')
		return (53);
	if (c >= '0' && c <= '9')
		return (54 + (c - 48));
	return (-1);
}

void	list_append(char **list, char *prefix)
{
	int i;

	i = 0;
	while (list[i] != NULL)
		i++;
	list[i] = ft_strdup(prefix);
}

void	reset_list(char **list, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		list[i] = NULL;
		i++;
	}
}
