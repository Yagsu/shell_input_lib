/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_complete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:42:20 by jesse             #+#    #+#             */
/*   Updated: 2020/09/26 23:51:00 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	init_handler(struct s_complete_handler *handler)
{
	handler->show_suggestion = 0;
	handler->size = 0;
	handler->offset = 0;
	handler->index = 0;
	handler->line = NULL;
}

void	free_handler(struct s_complete_handler *handler)
{
	int i;

	if (handler->line)
	{
		i = 0;
		while (i < handler->size)
		{
			if (handler->line[i].data)
				free(handler->line[i].data);
			i++;
		}
		free(handler->line);
	}
}

int		handle_keys(struct s_term_config *term,
		struct s_complete_handler *handler)
{
	char c;

	read(STDIN_FILENO, &c, 1);
	if (c == TAB)
		handler->index = (handler->index + 1) % handler->size;
	else if (c == ESC)
	{
		update_screen(term, NULL);
		return (1);
	}
	else
	{
		if (c == ENTER)
			term->status = DONE;
		buffer_append_at(&term->line, term->pos, handler->line[handler->index].data, handler->line[handler->index].size);
		term->pos += handler->line[handler->index].size;
		add_state(term);
		handle_key(c, term);
		update_screen(term, NULL);
		return (1);
	}
	return (0);
}

void	print_suggestion(struct s_term_config *term,
		struct s_complete_handler *handler)
{
	handler->show_suggestion = 1;
	handler->offset = handler->line[handler->index].size;
	update_screen(term, handler);
	handler->show_suggestion = 0;
	handler->offset = 0;
}

void	editor_complete(char c, struct s_term_config *term)
{
	struct s_complete_handler	handler;
	int							stop;

	(void)c;
	init_handler(&handler);
	if (get_trie(&handler, term) == -1)
		return ;
	stop = 0;
	while (!stop)
	{
		if (handler.index < handler.size)
			print_suggestion(term, &handler);
		stop = handle_keys(term, &handler);
	}
	free_handler(&handler);
	return ;
}
