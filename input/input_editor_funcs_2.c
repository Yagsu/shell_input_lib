/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor_funcs_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:25:41 by jesse             #+#    #+#             */
/*   Updated: 2020/09/26 23:32:47 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	editor_delete(char c, struct s_term_config *term)
{
	(void)c;
	if (term->line.size > 0 && term->pos != term->line.size)
	{
		ft_memmove(term->line.data + term->pos,
		term->line.data + term->pos + 1, term->line.size - term->pos);
		term->line.size--;
		term->line.data[term->line.size] = '\0';
		add_state(term);
		update_screen(term, NULL);
	}
}

void	editor_word_right(char c, struct s_term_config *term)
{
	int new_pos;

	(void)c;
	if (term->line.size == 0)
		return ;
	new_pos = word_border_at_right(term);
	if (new_pos == -1)
		return ;
	term->pos = new_pos;
	update_screen(term, NULL);
}

void	editor_word_left(char c, struct s_term_config *term)
{
	int new_pos;

	(void)c;
	if (term->line.size == 0)
		return ;
	new_pos = word_border_at_left(term);
	if (new_pos == -1)
		return ;
	term->pos = new_pos;
	update_screen(term, NULL);
}

void	editor_word_delete(char c, struct s_term_config *term)
{
	int		to_pos;
	int		from_pos;
	char	*clipped;

	(void)c;
	clipped = NULL;
	if (term->line.size == 0)
		return ;
	to_pos = word_border_at_left(term);
	if (to_pos == -1)
		return ;
	from_pos = get_from_pos(term, term->pos);
	clipped = ft_strsub(term->line.data, to_pos, from_pos - to_pos);
	if (clipped)
	{
		add_to_clipboard(term, clipped);
		ft_memmove(term->line.data + to_pos, term->line.data + from_pos, term->line.size - from_pos);
		term->line.size -= (from_pos - to_pos);
		term->line.data[term->line.size] = '\0';
		term->pos = to_pos;
		free(clipped);
	}
	update_screen(term, NULL);
	add_state(term);
}

void	editor_home(char c, struct s_term_config *term)
{
	(void)c;
	if (term->line.size > 0)
		term->pos = 0;
	update_screen(term, NULL);
}
