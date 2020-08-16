/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:38:00 by jesse             #+#    #+#             */
/*   Updated: 2020/08/16 17:57:28 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	free_history(struct s_term_config *term)
{
	int i = 0;

	if (term->history.line)
	{
		while (i <= term->history.size)
		{
			if (term->history.line[i])
				free(term->history.line[i]);
			i++;
		}
		free(term->history.line);
	}
}

int		main()
{
	struct s_term_config	term;
	int						status;
	char					*line;

	status = 1;
	init_config(&term);
	editor_history_load(&term, HISTORY_FILE);
	while (status)
	{
		line = shell_get_input(&term);
		ft_printf("Line is: %s\n", line);
		if (line && !ft_strcmp(line, "exit"))
			status = 0;
		if (line)
			free(line);
		reset_config(&term);
	}
	editor_history_save(&term, HISTORY_FILE);
	free_history(&term);
	return (0);
}

// History