/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor_undo_redo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:10:48 by jesse             #+#    #+#             */
/*   Updated: 2020/09/26 23:51:15 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

struct s_state_buffer	*alloc_states(int size, struct s_state_buffer *src)
{
	struct s_state_buffer *new_state;

	new_state = (struct s_state_buffer *)malloc(sizeof(*new_state) * (size + 1));
	if (!new_state)
		return (NULL);
	if (size > 0)
		ft_memcpy(&new_state[1], src, size * (sizeof(struct s_state_buffer)));
	return (new_state);
}

void					shift_states(struct s_term_config *term)
{
	int i;

	i = 0;
	while (i < term->state_stack.index)
	{
		if (term->state_stack.state[i].data)
			free(term->state_stack.state[i].data);
		i++;
	}
	ft_memmove(term->state_stack.state, &term->state_stack.state[term->state_stack.index], (term->state_stack.size - term->state_stack.index) * sizeof(struct s_state_buffer));
	term->state_stack.size = (term->state_stack.size - term->state_stack.index);
}

void					add_state(struct s_term_config *term)
{
	struct s_state_buffer *states;

	if (term->state_stack.index > 0)
		shift_states(term);
	states = alloc_states(term->state_stack.size, term->state_stack.state);
	if (!states)
		return ;
	if (term->state_stack.state)
		free(term->state_stack.state);
	term->state_stack.state = states;
	term->state_stack.size++;
	term->state_stack.state[0].data = ft_strdup(term->line.data);
	term->state_stack.state[0].size = term->line.size;
	term->state_stack.state[0].capacity = term->line.capacity;
	term->state_stack.state[0].pos = term->pos;
	term->state_stack.index = 0;
}

void					editor_redo(char c, struct s_term_config *term)
{
	(void)c;
	if (term->state_stack.size > 0 && term->state_stack.index > 0)
	{
		if (term->line.data)
			free(term->line.data);
		term->state_stack.index--;
		term->line.data = ft_strdup(term->state_stack.state[term->state_stack.index].data);
		term->line.size = term->state_stack.state[term->state_stack.index].size;
		term->line.capacity = term->state_stack.state[term->state_stack.index].capacity;
		term->pos = term->state_stack.state[term->state_stack.index].pos;
	}
	update_screen(term, NULL);
}

void					editor_undo(char c, struct s_term_config *term)
{
	(void)c;
	if (term->state_stack.size > 0 && term->state_stack.index + 1 < term->state_stack.size)
	{
		if (term->line.data)
			free(term->line.data);
		term->state_stack.index++;
		term->line.data = ft_strdup(term->state_stack.state[term->state_stack.index].data);
		term->line.size = term->state_stack.state[term->state_stack.index].size;
		term->line.capacity = term->state_stack.state[term->state_stack.index].capacity;
		term->pos = term->state_stack.state[term->state_stack.index].pos;
	}
	update_screen(term, NULL);
}
