/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor_clipboard.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 19:18:48 by jesse             #+#    #+#             */
/*   Updated: 2020/09/26 23:51:03 by jesse            ###   ########.fr       */
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
			ptr[i].size = 0;
			ptr[i].capacity = 0;
		}
		i++;
	}
}

struct s_buffer	*allocate_clipboard(struct s_term_config *term, int size)
{
	struct s_buffer *new;

	new = (struct s_buffer *)malloc(sizeof(struct s_buffer) * (size + 1));
	init_new_buffer_list(new, size + 1);
	if (size > 0 && term->clipboard.mode == MODE_RING)
		ft_memcpy(&new[1], term->clipboard.line_stack, size * sizeof(struct s_buffer));
	if (term->clipboard.line_stack)
		free(term->clipboard.line_stack);
	return (new);
}

void			add_to_clipboard(struct s_term_config *term, char *str)
{
	if (!term->clipboard.line_stack || (term->clipboard.line_stack && term->clipboard.mode == MODE_RING))
		term->clipboard.line_stack = allocate_clipboard(term, term->clipboard.size);
	if (term->clipboard.mode == MODE_SINGLE && term->clipboard.line_stack)
	{
		if (term->clipboard.line_stack[0].data)
			free(term->clipboard.line_stack[0].data);
		term->clipboard.line_stack[0].size = 0;
	}
	term->clipboard.line_stack[0].data = ft_strdup(str);
	term->clipboard.line_stack[0].size = ft_strlen(str);
	term->clipboard.line_stack[0].capacity = term->clipboard.line_stack[0].size;
	if (term->clipboard.mode == MODE_RING || term->clipboard.size < 1)
		term->clipboard.size++;
	term->clipboard.index = 0;
}
