/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_esc_seq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:30:37 by jesse             #+#    #+#             */
/*   Updated: 2020/08/16 18:36:49 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		get_escape_seq()
{
	char	c;
	int		n;

	if ((n = read(STDIN_FILENO, &c, 1)) != 1)
		return ('\x1b');
	return (c);
}

int		parse_two_step(int c, int *i)
{
	if (c == 'A')
		return (*i = ARROW_UP);
	else if (c == 'B')
		return (*i = ARROW_DOWN);
	else if (c == 'D')
		return (*i = ARROW_LEFT);
	else if (c == 'C')
		return (*i = ARROW_RIGHT);
	else if (c == 'H')
		return (*i = HOME);
	return (0);
}

int		parse_three_step(int c, int *i)
{
	if (c >= 50 && c <= 54)
	{
		if (c == 51)
			*i = DEL;
		get_escape_seq();
		return (1);
	}
	return (0);
}

void	get_c(int *i)
{
	int c;

	c = get_escape_seq();
	if (parse_two_step(c, i) != 0)
		return ;
	if (parse_three_step(c, i) != 0)
		return ;
}

void	parse_escape_seq(int *c)
{
	char	seq[3];
	int		n;

	if (*c == '\x1b')
	{
		if ((n = read(STDIN_FILENO, &seq[0], 1)) != 1)
			return ;
		if (seq[0] == '[')
			get_c(c);
	}
}
