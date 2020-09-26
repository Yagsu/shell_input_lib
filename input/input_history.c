/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:15:21 by jesse             #+#    #+#             */
/*   Updated: 2020/09/26 23:51:21 by jesse            ###   ########.fr       */
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

struct s_buffer *allocate_history(struct s_buffer *history, int size, int new_size)
{
	struct s_buffer *list;

	list = malloc(sizeof(struct s_buffer) * (new_size + 1));
	if (!list)
		return (NULL);
	list[1].data = NULL;
	list[1].size = 0;
	list[1].capacity = 0;
	list[0].data = NULL;
    list[0].size = 0;
	list[0].capacity = 0;
	if (history[0].data)
		free(history[0].data);
	if (size > 0)
		ft_memcpy(&list[2], &history[1], size * sizeof(struct s_buffer));
	return (list);
}

void			editor_history_add(struct s_term_config *term, char *str)
{
	struct s_buffer *new;

	if (term->history.line && term->history.size > 0 && !ft_strcmp(term->history.line[1].data, str))
		return ;
	if (ft_strlen(str) == 0)
		return ;
	new = allocate_history(term->history.line, term->history.size, term->history.size + 1);
	if (!new)
		return ;
	if (term->history.line)
		free(term->history.line);
	term->history.line = new;
	term->history.line[1].data = ft_strdup(str);
	term->history.line[1].size = ft_strlen(str);
	term->history.line[1].capacity = term->history.line[1].size;
	term->history.size++;
	term->history.index = 0;
}

void			editor_history_up(char c, struct s_term_config *term)
{
	(void)c;
	if (term->history.size > 0 && term->history.index < term->history.size)
	{
		if (term->history.line[term->history.index].data)
			free(term->history.line[term->history.index].data);
		if (term->line.data)
		{
			term->history.line[term->history.index].data = ft_strdup(term->line.data);
			term->history.line[term->history.index].size = term->line.size;
			term->history.line[term->history.index].capacity = term->line.capacity;
			free(term->line.data);
		}
		if (term->history.index < term->history.size)
			term->history.index++;
		term->line.data = ft_strdup(term->history.line[term->history.index].data);
		term->line.size = term->history.line[term->history.index].size;
		term->line.capacity = term->history.line[term->history.index].capacity;
		term->pos = term->line.size;
		clear_states(term);
		add_state(term);
	}
	update_screen(term, NULL);
}

void			editor_history_down(char c, struct s_term_config *term)
{
	(void)c;
	if (term->history.size > 0)
	{
		if (term->history.line[term->history.index].data)
			free(term->history.line[term->history.index].data);
		if (term->line.data)
		{
			term->history.line[term->history.index].data = ft_strdup(term->line.data);
			term->history.line[term->history.index].size = term->line.size;
			term->history.line[term->history.index].capacity = term->line.capacity;
			free(term->line.data);
		}
		if (term->history.index > 0)
			term->history.index--;
		term->line.data = ft_strdup(term->history.line[term->history.index].data);
		term->line.size = term->history.line[term->history.index].size;
		term->line.capacity = term->history.line[term->history.index].capacity;
		term->pos = term->line.size;
		clear_states(term);
		add_state(term);
	}
	update_screen(term, NULL);
}

int				editor_history_load(struct s_term_config *term, const char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (get_next_line(fd, &line))
	{
		editor_history_add(term, line);
		free(line);
	}
	close(fd);
	return (0);
}

int				editor_history_save(struct s_term_config *term, const char *file)
{
	int		fd;
	int		i;

	fd = open(file, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
	if (fd < 0)
	{
		free_history(term);
		return (-1);
	}
	i = term->history.size;
	while (i > 0)
    {
		if (term->history.line[i].data == NULL || ft_strlen(term->history.line[i].data) == 0)
		{
			i--;
			continue;
		}
        if (i == 1)
            ft_fprintf(fd, "%s", term->history.line[i--].data);
        else
            ft_fprintf(fd, "%s\n", term->history.line[i--].data);
    }
	close(fd);
	free_history(term);
	return (0);
}
