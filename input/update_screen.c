/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 02:08:07 by jesse             #+#    #+#             */
/*   Updated: 2020/09/26 23:49:27 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	get_settings(struct s_refresh_settings *ref, struct s_term_config *term, struct s_complete_handler *handler)
{
	if (handler)
		ref->pos_offset = handler->offset ? handler->offset : 0;
	else
		ref->pos_offset = 0;	
	ref->prompt_len = ft_strlen(term->prompt.prompt);
	ref->rows = (ref->prompt_len + term->line.size + \
	term->window_cols - 1) / term->window_cols;
	ref->cursor_pos = (ref->prompt_len + term->pos_old + \
	term->window_cols) / term->window_cols;
	ref->old_rows = term->used_rows;
}

void	clear_rows(struct s_buffer *buffer, struct s_refresh_settings *ref)
{
	char	*seq;
	int		i;

	if (ref->old_rows - ref->cursor_pos > 0)
	{
		ft_snprintf(&seq, "\x1b[%dB", ref->old_rows - ref->cursor_pos);
		buffer_append(buffer, seq, ft_strlen(seq));
		free(seq);
	}
	i = 0;
	while (i < ref->old_rows - 1)
	{
		ft_snprintf(&seq, "\r\x1b[0K\x1b[1A");
		buffer_append(buffer, seq, ft_strlen(seq));
		free(seq);
		i++;
	}
	ft_snprintf(&seq, "\r\x1b[0K");
	buffer_append(buffer, seq, ft_strlen(seq));
	free(seq);
}

void	update_cursor(struct s_buffer *buffer,
		struct s_refresh_settings *ref, struct s_term_config *term)
{
	char	*seq;

	ref->cursor_pos2 = (ref->prompt_len + term->pos + \
	term->window_cols + ref->pos_offset) / term->window_cols;
	if (ref->rows - ref->cursor_pos2 > 0)
	{
		ft_snprintf(&seq, "\x1b[%dA", ref->rows - ref->cursor_pos2);
		buffer_append(buffer, seq, ft_strlen(seq));
		free(seq);
	}
	ref->cols = (ref->prompt_len + term->pos + ref->pos_offset) % term->window_cols;
	if (ref->cols)
		ft_snprintf(&seq, "\r\x1b[%dC", ref->cols);
	else
		ft_snprintf(&seq, "\r");
	buffer_append(buffer, seq, ft_strlen(seq));
	free(seq);
}

void	append_row(struct s_buffer *buffer,
		struct s_refresh_settings *ref, struct s_term_config *term)
{
	char *seq;

	buffer_append(buffer, "\n", 1);
	ft_snprintf(&seq, "\r");
	buffer_append(buffer, seq, ft_strlen(seq));
	free(seq);
	ref->rows++;
	if (ref->rows > term->used_rows)
		term->used_rows = ref->rows;
}


void	append_line(struct s_buffer *buffer, struct s_term_config *term, struct s_complete_handler *handler)
{
	if (handler && handler->show_suggestion)
	{
		buffer_append(buffer, term->line.data, term->pos);
		buffer_append(buffer, handler->line[handler->index].data, handler->line[handler->index].size);
		buffer_append(buffer, &term->line.data[term->pos], term->line.size - term->pos);
	}
	else
		buffer_append(buffer, term->line.data, term->line.size);
}

void	update_screen(struct s_term_config *term, struct s_complete_handler *handler)
{
	struct s_refresh_settings	ref;
	struct s_buffer				buffer;

	get_settings(&ref, term, handler);
	init_buffer(&buffer);
	if (ref.rows > term->used_rows)
		term->used_rows = ref.rows;
	clear_rows(&buffer, &ref);
	buffer_append(&buffer, term->prompt.prompt, ref.prompt_len);
	append_line(&buffer, term, handler);
	if (term->pos && term->pos == term->line.size &&
	(term->prompt.len + term->pos) % term->window_cols == 0)
		append_row(&buffer, &ref, term);
	update_cursor(&buffer, &ref, term);
	term->pos_old = term->pos;
	write(STDIN_FILENO, buffer.data, buffer.size);
	buffer_free(&buffer);
}
