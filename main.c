/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:38:00 by jesse             #+#    #+#             */
/*   Updated: 2020/08/21 19:44:39 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	free_history(struct s_term_config *term)
{
	int i;

	i = 0;
	if (term->history.line)
	{
		while (i <= term->history.size)
		{
			if (term->history.line[i].data)
				free(term->history.line[i].data);
			i++;
		}
		free(term->history.line);
	}
}

void	free_clipboard(struct s_term_config *term)
{
	int i;

	i = 0;
	if (term->clipboard.line_stack)
	{
		while (i <= term->clipboard.size - 1)
		{
			if (term->clipboard.line_stack[i].data)
				free(term->clipboard.line_stack[i].data);
			i++;
		}
		free(term->clipboard.line_stack);
	}
}

void	init_history(struct s_term_config *term)
{
	term->history.line = malloc(sizeof(struct s_buffer));
	term->history.line[0].data = NULL;
	term->history.line[0].len = 0;
	editor_history_load(term, HISTORY_FILE);
}

int		main()
{
	struct s_term_config	term;
	int						status;
	char					*line;

	status = 1;
	init_config(&term);
	init_history(&term);
	while (status)
	{
		line = shell_get_input(&term);
		ft_printf("Line is: %s\n", line);
		if (line && !ft_strcmp(line, "exit"))
			status = 0;
		if (line && !ft_strcmp(line, "history"))
			print_history(&term);
		if (line)
			free(line);
		reset_config(&term);
	}
	editor_history_save(&term, HISTORY_FILE);
	free_clipboard(&term);
	return (0);
}

// History