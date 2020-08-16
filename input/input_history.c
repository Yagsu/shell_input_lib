/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:15:21 by jesse             #+#    #+#             */
/*   Updated: 2020/08/16 18:06:27 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	reset_arr(char **list, int size)
{
	int		i;

	i = 0;
	while (i <= size - 1)
	{
		list[i] = NULL;
		i++;
	}
}

char	**allocate_history(char **history, int size, int new_size)
{
	char **res;

	res = malloc(sizeof(*res) * (new_size + 1));
	if (!res)
		return (NULL);
	reset_arr(res, new_size + 1);
    if (size > 0)
		ft_memcpy(&res[2], &history[1], size * sizeof(*res));
	return (res);
}

void	editor_history_add(struct s_term_config *term, char *str)
{
	char **new;

	if (term->history.line && term->history.size > 0 && !ft_strcmp(term->history.line[1], str))
		return ;
	new = allocate_history(term->history.line, term->history.size, term->history.size + 1);
	if (!new)
		return ;
	if (term->history.line)
		free(term->history.line);
	term->history.line = new;
	term->history.line[1] = ft_strdup(str);
	term->history.size++;
}

void	editor_history_up(char c, struct s_term_config *term)
{
	(void)c;
	if (term->history.size > 0)
	{
		if (term->history.line[term->history.index])
			free(term->history.line[term->history.index]);
		if (term->line.len)
			term->history.line[term->history.index] = ft_strdup(term->line.data);
		else
			term->history.line[term->history.index] = ft_strdup("");
		if (term->history.index < term->history.size)
			term->history.index++;
		if (term->line.data)
			free(term->line.data);
		term->line.data = term->history.line[term->history.index] ? ft_strdup(term->history.line[term->history.index]) : NULL;
		term->line.len = term->line.data ? ft_strlen(term->line.data) : 0;
		term->pos = term->line.len;
		clear_states(term);
	}
	update_screen(term);
}

void	editor_history_down(char c, struct s_term_config *term)
{
	(void)c;
	if (term->history.size > 0)
	{
		if (term->history.line[term->history.index])
			free(term->history.line[term->history.index]);
		if (term->line.len)
			term->history.line[term->history.index] = ft_strdup(term->line.data);
		else
			term->history.line[term->history.index] = ft_strdup("");
		if (term->history.index > 0)
			term->history.index--;
		if (term->line.data)
			free(term->line.data);
		term->line.data = term->history.line[term->history.index] ? ft_strdup(term->history.line[term->history.index]) : NULL;
		term->line.len = term->line.data ? ft_strlen(term->line.data) : 0;
		term->pos = term->line.len;
		clear_states(term);
	}
	update_screen(term);
}

int		editor_history_load(struct s_term_config *term, const char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	term->history.line = malloc(sizeof(*term->history.line) * 2);
    term->history.line[1] = NULL;
	while (get_next_line(fd, &line))
	{
		editor_history_add(term, line);
		free(line);
	}
	close(fd);
	return (0);
}

int		editor_history_save(struct s_term_config *term, const char *file)
{
	int		fd;
	int		i;

	fd = open(file, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
	if (fd < 0)
		return (-1);
	i = term->history.size;
	while (i)
    {
		if (term->history.line[i] == NULL || ft_strlen(term->history.line[i]) == 0)
		{
			i--;
			continue;
		}
        if (i == 1)
            ft_fprintf(fd, "%s", term->history.line[i--]);
        else
            ft_fprintf(fd, "%s\n", term->history.line[i--]);
    }
	close(fd);
	return (0);
}
