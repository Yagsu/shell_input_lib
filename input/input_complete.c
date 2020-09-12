/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_complete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:42:20 by jesse             #+#    #+#             */
/*   Updated: 2020/09/11 19:30:13 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	init_handler(struct s_complete_handler *handler)
{
	handler->size = 0;
	handler->index = 0;
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
		update_screen(term);
		return (1);
	}
	else
	{
		if (c == ENTER)
			term->status = DONE;
		free(term->line.data);
		term->line.data = ft_strdup(handler->line[handler->index].data);
		term->line.size = ft_strlen(handler->line[handler->index].data);
		term->pos = handler->line[handler->index].pos;
		add_state(term);
		handle_key(c, term);
		update_screen(term);
		return (1);
	}
	return (0);
}

void	print_suggestion(struct s_term_config *term,
		struct s_complete_handler *handler)
{
	struct s_term_config		backup;

	backup = *term;
	term->line.data = handler->line[handler->index].data;
	term->line.size = ft_strlen(handler->line[handler->index].data);
	term->pos = handler->line[handler->index].pos;
	update_screen(term);
	term->line.size = backup.line.size;
	term->line.data = backup.line.data;
	term->pos = backup.pos;
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
