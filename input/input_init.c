/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 01:59:16 by jesse             #+#    #+#             */
/*   Updated: 2020/08/21 18:13:11 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		get_window_size(int *rows, int *cols)
{
	struct winsize ws;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0)
		return (-1);
	else
	{
		*cols = ws.ws_col;
		*rows = ws.ws_row;
		return (0);
	}
}

int		init_editor(struct s_term_config *term)
{
	struct termios raw;

	if (tcgetattr(STDIN_FILENO, &term->orig_termios) == -1)
		return (-1);
	raw = term->orig_termios;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN);
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) < 0)
		return (-1);
	return (0);
}

void	restore_term(struct s_term_config *term)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term->orig_termios);
}

void	init_config(struct s_term_config *term)
{
	if (get_window_size(&term->window_rows, &term->window_cols) == -1)
		exit(1);
	term->pos = 0;
	term->pos_old = 0;
	term->used_rows = 0;
	term->line.len = 0;
	term->line.data = NULL;
	term->clipboard.index = 0;
	term->clipboard.size = 0;
	term->clipboard.mode = MODE_SINGLE;
	term->clipboard.line_stack = NULL;
	term->history.line = NULL;
	term->history.index = 0;
	term->history.size = 0;
	term->state_stack.index = 0;
	term->state_stack.size = 0;
	term->state_stack.state = NULL;
}

void	reset_config(struct s_term_config *term)
{
	term->pos = 0;
	term->pos_old = 0;
	term->used_rows = 0;
	term->line.len = 0;
	term->line.data = NULL;
	term->history.index = 0;
	if (term->prompt.prompt)
		free(term->prompt.prompt);
}

void	free_config(struct s_term_config *term)
{
	if (term->prompt.prompt)
		free(term->prompt.prompt);
}
