/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_trie.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:28:13 by jesse             #+#    #+#             */
/*   Updated: 2020/09/26 23:06:08 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOCOMPLETE_TRIE_H
# define AUTOCOMPLETE_TRIE_H

# define ALPHABET_SIZE 63

# include <sys/stat.h>
# include <dirent.h>

typedef struct	s_trie_node
{
	struct s_trie_node	*children[ALPHABET_SIZE];
	int					end_of_word;
}				t_trie_node;

/*
** Functions to manage and search a prefix tree
*/

t_trie_node		*get_node(void);
void			trie_add(t_trie_node *root, const char *word);
void			trie_add_from_path(t_trie_node *root, char *path);
void			trie_free(t_trie_node *root);

int				trie_matches(t_trie_node *root, char *prefix, int depth);
void			trie_complete(t_trie_node *root, char *prefix, char **list, int depth);
int				trie_search(t_trie_node *root, const char *word);

int				verify_path(char **path);
int				verify_query(char *query);

int				is_last_node(t_trie_node *root);
char			*string_from_char(int i);
int				char_to_index(char c);
void			reset_list(char **list, int n);
void			list_append(char **list, char *prefix);

#endif
