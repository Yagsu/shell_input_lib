/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:31:14 by jesse             #+#    #+#             */
/*   Updated: 2020/07/19 01:47:47 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		has_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int		check_local_dir(char **path)
{
	struct stat	sb;
	char		temp[500];
	char		*s;

	ft_bzero(temp, 500);
	ft_strcat(temp, "./");
	s = ft_strdup(*path);
	ft_strcat(temp, s);
	free(s);
	if (stat(temp, &sb) == -1)
		return (-1);
	if (S_ISDIR(sb.st_mode))
	{
		free((*path));
		(*path) = ft_strdup(temp);
		return (0);
	}
	return (-1);
}

int		check_path(char *str)
{
	struct stat sb;

	if (stat(str, &sb) == -1)
		return (-1);
	if (S_ISDIR(sb.st_mode))
		return (0);
	return (-1);
}

int		verify_path(char **path)
{
	if (has_slash(*path) && ((*path)[0] == '/' || (*path)[0] == '.'))
		return (check_path(*path));
	else if (has_slash(*path))
		return (check_local_dir(path));
	else
	{
		if (*path)
			free(*path);
		(*path) = ft_strdup(".");
		return (0);
	}
	return (-1);
}
