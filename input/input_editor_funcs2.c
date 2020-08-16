/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor_funcs2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:25:41 by jesse             #+#    #+#             */
/*   Updated: 2020/08/16 17:07:22 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	editor_delete(char c, struct s_term_config *term)
{
	(void)c;
	if (term->line.len > 0 && term->pos != term->line.len)
	{
		ft_memmove(term->line.data + term->pos,
		term->line.data + term->pos + 1, term->line.len - term->pos);
		term->line.len--;
		term->line.data[term->line.len] = '\0';
		add_state(term);
		update_screen(term);
	}
}

void	editor_word_right(char c, struct s_term_config *term)
{
	int new_pos;

	(void)c;
	if (term->line.len == 0)
		return ;
	new_pos = word_border_at_right(term);
	if (new_pos == -1)
		return ;
	term->pos = new_pos;
	update_screen(term);
}

void	editor_word_left(char c, struct s_term_config *term)
{
	int new_pos;

	(void)c;
	if (term->line.len == 0)
		return ;
	new_pos = word_border_at_left(term);
	if (new_pos == -1)
		return ;
	term->pos = new_pos;
	update_screen(term);
}

void	editor_word_delete(char c, struct s_term_config *term)
{
	int new_pos;
	int	from_pos;

	(void)c;
	if (term->line.len == 0)
		return ;
	new_pos = word_border_at_left(term);
	if (new_pos == -1)
		return ;
	from_pos = term->pos;
	if (!ft_iswhitespace(term->line.data[from_pos]))
		while (from_pos > 1 && !ft_iswhitespace(term->line.data[from_pos - 1]))
			from_pos--;
	ft_memmove(term->line.data + new_pos, term->line.data + from_pos, term->line.len - from_pos);
	term->line.len -= (from_pos - new_pos);
	term->line.data[term->line.len] = '\0';
	term->pos -= (from_pos - new_pos);
	update_screen(term);
	add_state(term);
}

void	editor_home(char c, struct s_term_config *term)
{
	(void)c;
	if (term->line.len > 0)
		term->pos = 0;
	update_screen(term);
}
