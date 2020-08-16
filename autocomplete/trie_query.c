/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_query.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:25:23 by jesse             #+#    #+#             */
/*   Updated: 2020/07/19 01:47:45 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		trie_search(t_trie_node *root, const char *word)
{
	int			level;
	int			len;
	int			index;
	t_trie_node *temp;

	len = ft_strlen(word);
	temp = root;
	level = 0;
	while (level < len)
	{
		index = char_to_index(word[level]);
		if (!temp->children[index])
			return (0);
		temp = temp->children[index];
		level++;
	}
	return (temp != NULL && temp->end_of_word);
}

void	trie_complete(t_trie_node *root, char *prefix, char **list)
{
	int		i;
	char	*temp;

	if (root->end_of_word)
		list_append(list, prefix);
	if (is_last_node(root))
		return ;
	i = 0;
	while (i < ALPHABET_SIZE)
	{
		if (root->children[i])
		{
			temp = ft_strjoin_f(ft_strdup(prefix), string_from_char(i));
			trie_complete(root->children[i], temp, list);
			free(temp);
		}
		i++;
	}
}

int		trie_matches(t_trie_node *root, char *prefix)
{
	char	*temp;
	int		count;
	int		i;

	count = 0;
	if (ft_strlen(prefix) == 0)
		return (0);
	if (root->end_of_word)
		count++;
	if (is_last_node(root))
		return (count);
	i = 0;
	while (i < ALPHABET_SIZE)
	{
		if (root->children[i])
		{
			temp = ft_strjoin_f(ft_strdup(prefix), string_from_char(i));
			count += trie_matches(root->children[i], temp);
			free(temp);
		}
		i++;
	}
	return (count);
}

int		get_list(t_trie_node *root, char *word, char **list)
{
	if (root->end_of_word && is_last_node(root))
	{
		list_append(list, word);
		return (1);
	}
	if (!is_last_node(root))
	{
		trie_complete(root, word, list);
		return (1);
	}
	return (0);
}

char	**trie_get_suggestions_arr(t_trie_node *root,
		const char *word, struct s_complete_handler *handler)
{
	t_trie_node		*temp;
	char			**list;
	int				index;
	int				level;

	temp = root;
	level = 0;
	while (level < (int)ft_strlen(word))
	{
		index = char_to_index(word[level]);
		if (!temp->children[index])
			return (NULL);
		temp = temp->children[index];
		level++;
	}
	handler->size = trie_matches(temp, (char *)word);
	list = (char **)malloc(sizeof(char *) * (handler->size + 1));
	reset_list(list, handler->size + 1);
	if (get_list(temp, (char *)word, list))
		return (list);
	return (NULL);
}
