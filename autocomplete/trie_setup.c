/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:26:10 by jesse             #+#    #+#             */
/*   Updated: 2020/09/26 23:51:34 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void		trie_add(t_trie_node *root, const char *word)
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
		if (index == -1)
			break ;
		if (!temp->children[index])
			temp->children[index] = get_node();
		temp = temp->children[index];
		level++;
	}
	temp->end_of_word = 1;
}

void		trie_add_from_path(t_trie_node *root, char *path)
{
	DIR				*dir;
	struct dirent	*d;

	dir = opendir(path);
	if (dir)
	{
		while ((d = readdir(dir)) != NULL)
			trie_add(root, d->d_name);
	}
	closedir(dir);
}

void		trie_free(t_trie_node *root)
{
	int	i;

	i = 0;
	if (root)
	{
		while (i < ALPHABET_SIZE)
		{
			if (root->children[i])
				trie_free(root->children[i]);
			i++;
		}
		free(root);
	}
}

char		**trie_get_list(t_trie_node *root, char *query,
			struct s_complete_handler *handler, struct s_term_config *term)
{
	char	**list;
	int		i;

	(void)term;
	list = trie_get_suggestions_arr(root, query, handler);
	if (list)
	{
		handler->line = (struct s_buffer *)malloc(sizeof(struct s_buffer) *
		(handler->size + 1));
		ft_bzero(handler->line, handler->size + 1);
		i = 0;
		while (i < handler->size)
		{
			handler->line[i].data = list[i];
			handler->line[i].size = ft_strlen(list[i]);
			handler->line[i].capacity = handler->line[i].size;
			i++;
		}
		free(list);
	}
	return (NULL);
}

int			get_trie(struct s_complete_handler *handler,
			struct s_term_config *term)
{
	char			*path;
	char			*query;
	t_trie_node		*root;

	path = word_at_pos(term);
	if (path)
	{
		query = word_from_path(path);
		if (verify_path(&path) == -1)
			return (free_path_query(path, query));
		if (verify_query(query) == -1)
			return (free_path_query(path, query));
		if (ft_strlen(query) > 0)
		{
			root = get_node();
			trie_add_from_path(root, path);
			trie_get_list(root, query, handler, term);
			trie_free(root);
		}
		free(query);
		free(path);
	}
	if (!handler->line || !handler->size || !path)
		return (-1);
	return (0);
}
