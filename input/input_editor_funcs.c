/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 02:08:41 by jesse             #+#    #+#             */
/*   Updated: 2020/09/26 23:51:09 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	editor_backspace(char c, struct s_term_config *term)
{
	(void)c;
	if (term->pos > 0 && term->line.size > 0)
	{
		ft_memmove(term->line.data + term->pos - 1,
		term->line.data + term->pos, term->line.size - term->pos);
		term->pos--;
		term->line.size--;
		term->line.data[term->line.size] = '\0';
		add_state(term);
		update_screen(term, NULL);
	}
}

void	editor_enter(char c, struct s_term_config *term)
{
	(void)c;
	if (term->pos != term->line.size)
	{
		term->pos = term->line.size;
		update_screen(term, NULL);
	}
	if (term->line.data)
		editor_history_add(term, term->line.data);
	term->status = DONE;
}

void	editor_arrow_right(char c, struct s_term_config *term)
{
	(void)c;
	if (term->pos < term->line.size)
	{
		term->pos++;
		update_screen(term, NULL);
	}
}

void	editor_arrow_left(char c, struct s_term_config *term)
{
	(void)c;
	if (term->pos > 0)
	{
		term->pos--;
		update_screen(term, NULL);
	}
}

void	editor_insert(char c, struct s_term_config *term)
{
	int		old_capacity;

	old_capacity = term->line.capacity;
	if (term->line.size + 1 > term->line.capacity)
	{
		term->line.capacity = GROW_CAPACITY(old_capacity);
		term->line.data = GROW_ARRAY(char, term->line.data, old_capacity, term->line.capacity);
	}
	if (term->line.size != term->pos)
		ft_memmove(term->line.data + term->pos + 1,
		term->line.data + term->pos, term->line.size - term->pos);
	term->line.data[term->pos] = c;
	term->line.size++;
	term->pos++;
	term->line.data[term->line.size] = '\0';
	add_state(term);
	update_screen(term, NULL);
}
