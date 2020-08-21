/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 02:01:47 by jesse             #+#    #+#             */
/*   Updated: 2020/08/21 20:04:47 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static const t_key g_functable[] =
{
	{BACKSPACE, &editor_backspace},
	{PRINTABLE, &editor_insert},
	{ARROW_UP, &editor_history_up},
	{ARROW_DOWN, &editor_history_down},
	{ARROW_RIGHT, &editor_arrow_right},
	{ARROW_LEFT, &editor_arrow_left},
	{CTRL_B, &editor_word_left},
	{CTRL_F, &editor_word_right},
	{CTRL_G, &editor_word_delete},
	{CTRL_U, &editor_undo},
	{CTRL_R, &editor_redo},
	{CTRL_K, &editor_kill_end},
	{CTRL_W, &editor_kill_start},
	{CTRL_Y, &editor_paste},
	{CTRL_L, &editor_clear_rows},
	{HOME, &editor_home},
	{DEL, &editor_delete},
	{END, &editor_end},
	{TAB, &editor_complete},
	{ENTER, &editor_enter},
	{0, NULL}
};

int		parse_control_keys(int c, int *i)
{
	if (c == ('a' & 0x1F))
		return (*i = HOME);
	if (c == ('b' & 0x1F))
		return (*i = CTRL_B);
	if (c == ('f' & 0x1F))
		return (*i = CTRL_F);
	if (c == ('g' & 0x1F))
		return (*i = CTRL_G);
	if (c == ('u' & 0x1F))
		return (*i = CTRL_U);
	if (c == ('r' & 0x1F))
		return (*i = CTRL_R);
	if (c == ('d' & 0x1F))
		return (*i = DEL);
	if (c == ('k' & 0x1F))
		return (*i = CTRL_K);
	if (c == ('y' & 0x1F))
		return (*i = CTRL_Y);
	if (c == ('w' & 0x1F))
		return (*i = CTRL_W);
	if (c == ('l' & 0x1F))
		return (*i = CTRL_L);
	return (0);
}

int		is_valid_key(char c)
{
	int	i;
	int character;

	character = c;
	if (c == '\x1b')
		parse_escape_seq(&character);
	else
		parse_control_keys(c, &character);
	i = 0;
	while (g_functable[i].key != 0)
	{
		if (g_functable[i].key == character)
			return (i);
		i++;
	}
	return (-1);
}

void	handle_key(char c, struct s_term_config *term)
{
	int index;

	index = is_valid_key(c);
	if (index != -1)
		g_functable[index].fn(c, term);
	else if (ft_isprint(c))
		g_functable[1].fn(c, term);
}
