/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_editor_history_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 19:40:55 by jesse             #+#    #+#             */
/*   Updated: 2020/08/21 20:05:57 by jesse            ###   ########.fr       */
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
	while (i <= term->history.size)
	{
		if (term->history.line[i].len > len - 6)
		{
			to_print = ft_strsub(term->history.line[i].data, 0, len - 6);
			ft_printf("%*d %*s...\n", len, i, len * 2 - 3, to_print);
		}
		else
		{
			to_print = ft_strdup(term->history.line[i].data);
			ft_printf("%*d %*s\n", len, i, len * 2, to_print);
		}
		free(to_print);
		i++;
	}
}
