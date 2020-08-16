/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_buffer_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 01:58:02 by jesse             #+#    #+#             */
/*   Updated: 2020/07/31 16:18:55 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	init_buffer(struct s_buffer *buffer)
{
	buffer->data = NULL;
	buffer->len = 0;
}

char	*allocate_data(const char *s, int str_len, int total_len)
{
	char *new;

	new = (char *)malloc(sizeof(char) * (total_len + 1));
	ft_bzero(new, total_len + 1);
	ft_memcpy(new, s, str_len);
	return (new);
}

char	*finalize_buffer(struct s_term_config *term, struct s_line *line,
						char *str, char *word_at_pos)
{
	char	*new;
	int		len;
	int		pos;

	pos = ft_strlen(word_at_pos);
	len = (int)ft_strlen(str + pos);
	new = allocate_data(term->line.data,
	term->line.len, term->line.len + 2048);
	ft_memmove(new + term->pos + len, new + term->pos, term->line.len + len);
	ft_memcpy(new + term->pos, str + pos, len);
	line->pos = term->pos + len;
	return (new);
}

void	buffer_append(struct s_buffer *buffer, const char *s, int len)
{
	char *new_data;

	new_data = allocate_data(buffer->data, buffer->len, buffer->len + len);
	ft_memcpy(&new_data[buffer->len], s, len);
	free(buffer->data);
	buffer->data = new_data;
	buffer->len += len;
}

void	buffer_free(struct s_buffer *buffer)
{
	free(buffer->data);
}
