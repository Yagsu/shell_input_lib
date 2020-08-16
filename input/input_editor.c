/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 02:01:29 by jesse             #+#    #+#             */
/*   Updated: 2020/08/16 17:59:58 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		print_prompt(struct s_term_config *term)
{
	term->prompt.prompt = ft_strdup("$> ");
	term->prompt.len = ft_strlen(term->prompt.prompt);
	if (write(STDOUT_FILENO, term->prompt.prompt, term->prompt.len) == -1)
		return (-1);
	return (0);
}

void	clear_states(struct s_term_config *term)
{
	int index;

	index = 0;
	if (term->state_stack.state)
	{
		while (index < term->state_stack.size)
		{
			if (term->state_stack.state[index].data)
				free(term->state_stack.state[index].data);
			index++;
		}
		free(term->state_stack.state);
	}
	term->state_stack.state = NULL;
	term->state_stack.index = 0;
	term->state_stack.size = 0;
}

void	start_editor(struct s_term_config *term)
{
	int		n;
	char	c;

	if (print_prompt(term) == -1)
		return ;
	if (term->history.size == 0)
		editor_history_add(term, "");
	term->status = EDITING;
	term->line.data = ft_strdup("");
	add_state(term);
	while (term->status != DONE)
	{
		n = read(STDIN_FILENO, &c, 1);
		if (n <= 0)
			return ;
		handle_key(c, term);
	}
	clear_states(term);
}


int		toggle_editor(struct s_term_config *term)
{
	if (init_editor(term) == -1)
		return (-1);
	start_editor(term);
	restore_term(term);
	ft_printf("\n");
	return (0);
}

char	*shell_get_input(struct s_term_config *term)
{
	if (isatty(STDIN_FILENO))
		toggle_editor(term);
	return (term->line.data);
}
