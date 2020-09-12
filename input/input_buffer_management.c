/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_buffer_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 01:58:02 by jesse             #+#    #+#             */
/*   Updated: 2020/09/12 03:07:26 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	init_buffer(struct s_buffer *buffer)
{
	buffer->data = NULL;
	buffer->size = 0;
	buffer->capacity = 0;
}

void	*realloc_data(void *ptr, int old_size, int new_size)
{
	void *res;

	res = malloc(new_size);
	if (res == NULL)
		return (NULL);
	if (old_size > 0)
		ft_memcpy(res, ptr, old_size);	
	free(ptr);
	return (res);
}

void	*reallocate(void *pointer, int old_size, int new_size)
{
	void *result;
	
	if (new_size == 0)
	{
		free(pointer);
		return (NULL);
	}

	result = realloc_data(pointer, old_size, new_size);
	if (result == NULL)
		exit(1);
	return (result);
}

// char	*finalize_buffer(struct s_term_config *term, struct s_line *line,
// 						char *str, char *word_at_pos)
// {
// 	char	*new;
// 	int		len;
// 	int		pos;

// 	pos = ft_strlen(word_at_pos);
// 	len = (int)ft_strlen(str + pos);
// 	new = allocate_data(term->line.data,
// 	term->line.len, term->line.len + 2048);
// 	ft_memmove(new + term->pos + len, new + term->pos, term->line.len + len);
// 	ft_memcpy(new + term->pos, str + pos, len);
// 	line->pos = term->pos + len;
// 	return (new);
// }

void	buffer_append(struct s_buffer *buffer, const char *s, int len)
{
	int		old_capacity;

	old_capacity = buffer->size;
	if (buffer->size + len > buffer->capacity)
	{
		while (buffer->size + len + 1 > buffer->capacity)
			buffer->capacity = GROW_CAPACITY(buffer->capacity);
		buffer->data = GROW_ARRAY(char, buffer->data, old_capacity, buffer->capacity);
	}
	ft_memcpy(&buffer->data[old_capacity], s, len);
	buffer->size += len;
	buffer->data[buffer->size] = '\0';
}

void	buffer_free(struct s_buffer *buffer)
{
	free(buffer->data);
}
