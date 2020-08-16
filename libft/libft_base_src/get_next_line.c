/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:27:20 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/27 11:39:17 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_return_value(char **str, char **line, int fd, int file)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		ptr = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = ptr;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (file == BUFF_SIZE_GNL)
			get_next_line(fd, line);
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *str[FD_MAX_GNL];
	char		buffer[BUFF_SIZE_GNL + 1];
	char		*ptr;
	int			file;

	if (fd > FD_MAX_GNL)
		return (-1);
	if (fd < 0 || !line)
		return (-1);
	while ((file = read(fd, buffer, BUFF_SIZE_GNL)) > 0)
	{
		buffer[file] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(0);
		ptr = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = ptr;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (file < 0)
		return (-1);
	if (file == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (get_return_value(str, line, fd, file));
}
