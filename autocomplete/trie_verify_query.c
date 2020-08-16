/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_verify_query.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 22:53:51 by jesse             #+#    #+#             */
/*   Updated: 2020/07/19 01:41:36 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int			verify_query(char *query)
{
	int	i;

	i = 0;
	while (query[i])
	{
		if (!ft_isalnum(query[i]) && query[i] != '/' &&
			query[i] != '.' && query[i] != '_')
			return (-1);
		i++;
	}
	return (0);
}

t_trie_node	*get_node(void)
{
	int			i;
	t_trie_node *t_node;

	t_node = (t_trie_node *)malloc(sizeof(t_trie_node));
	i = 0;
	if (t_node)
	{
		t_node->end_of_word = 0;
		while (i < ALPHABET_SIZE)
		{
			t_node->children[i] = NULL;
			i++;
		}
	}
	return (t_node);
}
