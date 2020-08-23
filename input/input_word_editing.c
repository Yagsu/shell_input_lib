/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_word_editing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:23:30 by jesse             #+#    #+#             */
/*   Updated: 2020/08/23 14:23:37 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		get_from_pos(struct s_term_config *term, int pos)
{
	int from_pos;

	from_pos = pos;
	if (ft_iswhitespace(term->line.data[from_pos]) || (from_pos > 1 && ft_iswhitespace(term->line.data[from_pos - 1])))
		while (from_pos > 1 && !ft_iswhitespace(term->line.data[from_pos - 1]))
			from_pos--;
	else if (!ft_iswhitespace(term->line.data[from_pos]))
		while (from_pos < term->line.len && !ft_iswhitespace(term->line.data[from_pos]))
			from_pos++;
	return (from_pos);
}

int		word_border_at_left(struct s_term_config *term)
{
	int index;

	index = term->pos;
	if (index == 0)
		return (-1);
	if (index >= 0 && (ft_iswhitespace(term->line.data[index]) || ft_iswhitespace(term->line.data[index - 1]) || index == term->line.len))
	{
		index--;
		while (index >= 0 && term->line.data[index] && ft_iswhitespace(term->line.data[index]))
			index--;
	}
	if (index >= 0 && term->line.data[index] && !ft_iswhitespace(term->line.data[index]))
	{
		while (index > 0 && term->line.data[index] && !ft_iswhitespace(term->line.data[index - 1]))
			index--;
		return (index);
	}
	return (-1);
}

int		word_border_at_right(struct s_term_config *term)
{
	int index;

	index = term->pos;
	if (index == term->line.len)
		return (-1);
	if (index < term->line.len && (ft_iswhitespace(term->line.data[index]) || ft_iswhitespace(term->line.data[index + 1])))
	{
		index++;
		while (index >= 0 && term->line.data[index] && ft_iswhitespace(term->line.data[index]))
			index++;
	}		
	if (index >= 0 && term->line.data[index] && !ft_iswhitespace(term->line.data[index]))
	{
		while (index >= 0 && term->line.data[index] && !ft_iswhitespace(term->line.data[index]))
			index++;
		return (index);
	}
	return (-1);
}
