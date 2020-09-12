/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor_history_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 19:40:55 by jesse             #+#    #+#             */
/*   Updated: 2020/09/11 18:51:44 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	print_history(struct s_term_config *term)
{
	int		i;
	int		len;
	char	*to_print;

	i = 1;
	len = term->window_cols / 4;
	to_print = NULL;
	while (i <= term->history.size)
	{
		if (term->history.line[i].size > len - 6)
		{
			to_print = ft_strsub(term->history.line[i].data, 0, len - 6);
			ft_printf("%*d %*s...  │  %d\n", len, i, len * 2 - 3, to_print, i);
		}
		else
		{
			to_print = ft_strdup(term->history.line[i].data);
			ft_printf("%*d %*s  │  %d\n", len, i, len * 2, to_print, i);
		}
		if (to_print)
			free(to_print);
		i++;
	}
}
