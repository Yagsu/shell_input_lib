/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor_clipboard.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 19:18:48 by jesse             #+#    #+#             */
/*   Updated: 2020/08/21 19:38:21 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void			init_new_buffer_list(struct s_buffer *ptr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (ptr != NULL)
		{
			ptr[i].data = NULL;
			ptr[i].len = 0;
		}
		i++;
	}
}

void	prepare_buffer(struct s_term_config *term)
{
	char	*new_buffer;
	
	if (!term->line.data)
	{
		term->line.data = (char *)malloc(2);
		term->line.data[0] = '\0';
	}
	if (term->line.len > 0)
	{
		new_buffer = allocate_data(term->line.data,
					term->line.len, term->line.len + term->clipboard.line_stack[term->clipboard.index].len);
		free(term->line.data);
		term->line.data = new_buffer;
	}
	if (term->line.len != term->pos)
		ft_memmove(term->line.data + term->pos + term->clipboard.line_stack[term->clipboard.index].len,
		term->line.data + term->pos, term->line.len - term->pos);
}

struct s_buffer	*allocate_clipboard(struct s_term_config *term, int size)
{
	struct s_buffer *new;

	new = (struct s_buffer *)malloc(sizeof(struct s_buffer) * (size + 1));
	init_new_buffer_list(new, size + 1);
	if (size > 0 && term->clipboard.mode == MODE_RING)
		ft_memcpy(&new[1], term->clipboard.line_stack, size * sizeof(struct s_buffer));
	return (new);
}

void			add_to_clipboard(struct s_term_config *term, char *str)
{
	struct	s_buffer *buffer;

	if (!term->clipboard.line_stack || (term->clipboard.line_stack && term->clipboard.mode == MODE_RING))
	{
		buffer = allocate_clipboard(term, term->clipboard.size);
		if (term->clipboard.line_stack && term->clipboard.mode == MODE_RING)
			free(term->clipboard.line_stack);
		term->clipboard.line_stack = buffer;
	}
	if (term->clipboard.mode == MODE_SINGLE && term->clipboard.line_stack)
	{
		if (term->clipboard.line_stack[0].data)
			free(term->clipboard.line_stack[0].data);
		term->clipboard.line_stack[0].len = 0;
	}
	term->clipboard.line_stack[0].data = ft_strdup(str);
	term->clipboard.line_stack[0].len = ft_strlen(str);
	if (term->clipboard.mode == MODE_RING || term->clipboard.size < 1)
		term->clipboard.size++;
	term->clipboard.index = 0;
}
