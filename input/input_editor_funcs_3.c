/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor_funcs_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:58:55 by jesse             #+#    #+#             */
/*   Updated: 2020/08/21 19:35:26 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void			editor_end(char c, struct s_term_config *term)
{
	(void)c;
	if (term->line.len > 0 && term->pos != term->line.len)
	{
		term->pos = term->line.len;
		update_screen(term);
	}
}

void			editor_kill_end(char c, struct s_term_config *term)
{
	int len;
	char *clipped;		

	(void)c;
	if (term->pos != term->line.len && term->line.len > 0)
	{
		len = term->line.len - term->pos;
		clipped = ft_strsub(term->line.data, term->pos, len);
		if (clipped)
		{
			add_to_clipboard(term, clipped);
			ft_memset(term->line.data + term->pos, '\0', ft_strlen(clipped));
			term->line.len -= ft_strlen(clipped);
			free(clipped);
		}
		add_state(term);
		update_screen(term);
	}
}

void			editor_kill_start(char c, struct s_term_config *term)
{
	int len;
	char *clipped;		

	(void)c;
	if (term->pos != 0 && term->line.len > 0)
	{
		len = term->pos;
		clipped = ft_strsub(term->line.data, 0, len);
		if (clipped)
		{
			add_to_clipboard(term, clipped);
			ft_memmove(term->line.data, term->line.data + term->pos, ft_strlen(clipped));
			term->pos -= ft_strlen(clipped);
			term->line.len -= ft_strlen(clipped);
			free(clipped);
		}
		add_state(term);
		update_screen(term);
	}
}

void			editor_paste(char c, struct s_term_config *term)
{
	(void)c;
	if (term->clipboard.size > 0 && term->clipboard.index < term->clipboard.size)
	{
		prepare_buffer(term);
		ft_memcpy(&term->line.data[term->pos], term->clipboard.line_stack[term->clipboard.index].data, term->clipboard.line_stack[term->clipboard.index].len);
		term->line.len += term->clipboard.line_stack[term->clipboard.index].len;
		term->pos += term->clipboard.line_stack[term->clipboard.index].len;
		if (term->clipboard.mode == MODE_RING)
			term->clipboard.index++;
		add_state(term);
		update_screen(term);
	}
}
