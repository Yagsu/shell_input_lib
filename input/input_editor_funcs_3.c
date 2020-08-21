/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor_funcs_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:58:55 by jesse             #+#    #+#             */
/*   Updated: 2020/08/21 19:15:06 by jesse            ###   ########.fr       */
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

void			init_new(struct s_buffer *ptr, int size)
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

struct s_buffer	*allocate_clipboard(struct s_term_config *term, int size)
{
	struct s_buffer *new;

	new = (struct s_buffer *)malloc(sizeof(struct s_buffer) * (size + 1));
	init_new(new, size + 1);
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

void	editor_kill_end(char c, struct s_term_config *term)
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

void	editor_paste(char c, struct s_term_config *term)
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
