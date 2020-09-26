/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor_funcs_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:58:55 by jesse             #+#    #+#             */
/*   Updated: 2020/09/26 23:51:07 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void			editor_end(char c, struct s_term_config *term)
{
	(void)c;
	if (term->line.size > 0 && term->pos != term->line.size)
	{
		term->pos = term->line.size;
		update_screen(term, NULL);
	}
}

void			editor_kill_end(char c, struct s_term_config *term)
{
	int		len;
	char	*clipped;		

	(void)c;
	if (term->pos != term->line.size && term->line.size > 0)
	{
		len = term->line.size - term->pos;
		clipped = ft_strsub(term->line.data, term->pos, len);
		if (clipped)
		{
			add_to_clipboard(term, clipped);
			ft_memset(term->line.data + term->pos, '\0', ft_strlen(clipped));
			term->line.size -= ft_strlen(clipped);
			free(clipped);
		}
		add_state(term);
		update_screen(term, NULL);
	}
}

void			editor_kill_start(char c, struct s_term_config *term)
{
	int len;
	char *clipped;		

	(void)c;
	if (term->pos != 0 && term->line.size > 0)
	{
		len = term->pos;
		clipped = ft_strsub(term->line.data, 0, len);
		if (clipped)
		{
			add_to_clipboard(term, clipped);
			ft_memmove(term->line.data, &term->line.data[term->pos], len);
			term->pos -= ft_strlen(clipped);
			term->line.size -= ft_strlen(clipped);
			term->line.data[term->line.size] = '\0';
			free(clipped);
		}
		add_state(term);
		update_screen(term, NULL);
	}
}

void			editor_paste(char c, struct s_term_config *term)
{
	int		old_capacity;

	(void)c;
	if (term->clipboard.size > 0 && term->clipboard.index < term->clipboard.size)
	{
		old_capacity = term->line.capacity;
		if (term->line.size + term->clipboard.line_stack[term->clipboard.index].size > term->line.capacity)
		{
			while (term->line.size + term->clipboard.line_stack[term->clipboard.index].size > term->line.capacity)
				term->line.capacity = GROW_CAPACITY(term->line.capacity);
			term->line.data = GROW_ARRAY(char, term->line.data, old_capacity, term->line.capacity);
		}
		if (term->line.size != term->pos)
			ft_memmove(term->line.data + term->pos + term->clipboard.line_stack[term->clipboard.index].size,
			term->line.data + term->pos, term->line.size - term->pos);
		ft_memcpy(&term->line.data[term->pos], term->clipboard.line_stack[term->clipboard.index].data, term->clipboard.line_stack[term->clipboard.index].size);
		term->line.size += term->clipboard.line_stack[term->clipboard.index].size;
		term->pos += term->clipboard.line_stack[term->clipboard.index].size;
		if (term->clipboard.mode == MODE_RING)
			term->clipboard.index++;
		add_state(term);
		update_screen(term, NULL);
	}
}

void			editor_clear_rows(char c, struct s_term_config *term)
{
	struct s_buffer buffer;
	char	*seq;
	int		i;

	(void)c;
	init_buffer(&buffer);
	ft_snprintf(&seq, "\x1b[%dB", 99999999);
	buffer_append(&buffer, seq, ft_strlen(seq));
	free(seq);
	i = 0;
	while (i < term->window_rows - 1)
	{
		ft_snprintf(&seq, "\r\x1b[0K\x1b[1A");
		buffer_append(&buffer, seq, ft_strlen(seq));
		free(seq);
		i++;
	}
	ft_snprintf(&seq, "\r\x1b[0K");
	buffer_append(&buffer, seq, ft_strlen(seq));
	free(seq);
	write(STDIN_FILENO, buffer.data, buffer.size);
	buffer_free(&buffer);
	update_screen(term, NULL);
}
