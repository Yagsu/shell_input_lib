/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_complete_path_handling.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:24:37 by jesse             #+#    #+#             */
/*   Updated: 2020/08/21 23:31:16 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		get_arr_len(char **list)
{
	int i;

	i = 0;
	if (!list)
		return (0);
	while (list[i] != NULL)
		i++;
	return (i);
}

int		free_path_query(char *path, char *query)
{
	if (query)
		free(query);
	if (path)
		free(path);
	return (-1);
}

int		count_slashes(char *s)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '/')
			count++;
		i++;
	}
	return (count);
}

int		get_word_len(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*word_from_path(char *path)
{
	int		i;
	int		slashes;
	int		len;
	char	*word;

	len = 0;
	i = 0;
	word = NULL;
	slashes = count_slashes(path);
	if (!slashes)
		return (ft_strdup(path));
	while (slashes && path[i])
	{
		if (path[i] == '/')
			slashes--;
		i++;
	}
	len = get_word_len(&path[i]);
	word = malloc(sizeof(char) * len + 1);
	ft_strcpy(word, &path[i]);
	path[i] = '\0';
	return (word);
}
