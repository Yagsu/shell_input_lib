/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_word_at_cursor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:21:49 by jesse             #+#    #+#             */
/*   Updated: 2020/08/07 14:23:15 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		get_word_len_at_pos(char *s, int pos)
{
	int		index;
	int		len;

	index = pos - 1;
	len = 0;
	if (index >= 0 && s[index] && !ft_iswhitespace(s[index]))
	{
		while (index >= 0 && s[index] && !ft_iswhitespace(s[index]))
		{
			index--;
			len++;
		}
	}
	return (len);
}

void	copy_word(char **d, char *s, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		(*d)[j] = *(s - len + i);
		i++;
		j++;
	}
}

char	*word_at_pos(struct s_term_config *term)
{
	int		i;
	int		len;
	char	*word;

	i = term->pos;
	word = NULL;
	if (term->line.len > 0)
	{
		if (i > 0)
		{
			len = get_word_len_at_pos(term->line.data, i);
			word = (char *)malloc(sizeof(char) * (len + 1));
			word[len] = '\0';
			copy_word(&word, &term->line.data[i], len);
		}
	}
	return (word);
}
