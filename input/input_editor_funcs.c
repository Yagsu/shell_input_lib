/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 02:08:41 by jesse             #+#    #+#             */
/*   Updated: 2020/08/16 17:07:10 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	editor_backspace(char c, struct s_term_config *term)
{
	(void)c;
	if (term->pos > 0 && term->line.len > 0)
	{
		ft_memmove(term->line.data + term->pos - 1,
		term->line.data + term->pos, term->line.len - term->pos);
		term->pos--;
		term->line.len--;
		term->line.data[term->line.len] = '\0';
		add_state(term);
		update_screen(term);
	}
}

void	editor_enter(char c, struct s_term_config *term)
{
	(void)c;
	if (term->pos != term->line.len)
	{
		term->pos = term->line.len;
		update_screen(term);
	}
	if (term->line.len)
		editor_history_add(term, term->line.data);
	term->status = DONE;
}

void	editor_arrow_right(char c, struct s_term_config *term)
{
	(void)c;
	if (term->pos < term->line.len)
	{
		term->pos++;
		update_screen(term);
	}
}

void	editor_arrow_left(char c, struct s_term_config *term)
{
	(void)c;
	if (term->pos > 0)
	{
		term->pos--;
		update_screen(term);
	}
}

void	editor_insert(char c, struct s_term_config *term)
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
					term->line.len, term->line.len + 1);
		free(term->line.data);
		term->line.data = new_buffer;
	}
	if (term->line.len != term->pos)
		ft_memmove(term->line.data + term->pos + 1,
		term->line.data + term->pos, term->line.len - term->pos);
	term->line.data[term->pos] = c;
	term->line.len++;
	term->pos++;
	term->line.data[term->line.len] = '\0';
	add_state(term);
	update_screen(term);
}
