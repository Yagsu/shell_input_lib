/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:19:54 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:42:49 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static int		get_spaces_before_p(char *str)
{
	int	spaces;
	int	i;

	i = 0;
	spaces = 0;
	if (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			spaces++;
			i++;
		}
	}
	return (spaces);
}

char			*ft_strtrim_p(char const *s)
{
	char	*ptr;
	int		spaces[2];
	int		i;
	int		length;

	if (!s)
		return (NULL);
	spaces[0] = get_spaces_before_p((char *)s);
	if (spaces[0] == 0)
		return (ft_strdup((char *)s));
	if ((length = (ft_strlen((char *)s)) - spaces[0]) < 0)
		length = 0;
	if (!(ptr = (char *)malloc(length + 1)))
		return (NULL);
	i = 0;
	while (length)
	{
		ptr[i] = s[spaces[0] + i];
		i++;
		--length;
	}
	ptr[i] = '\0';
	return (ptr);
}

void			invalid_type(const char **format_position, char buffer[],
				t_buffer *list_buffer)
{
	char	*str;
	char	*tmp;
	int		len;

	len = 0;
	if (ft_strchr(*format_position, '%'))
	{
		len = (int)ft_strchr(*format_position, '%') - (int)*format_position;
		str = ft_strsub(*format_position, 0, len);
	}
	else
	{
		str = ft_strdup(*format_position);
		len = ft_strlen(str);
	}
	if (str[0] == ' ')
	{
		tmp = ft_strtrim_p(str);
		free(str);
		str = tmp;
	}
	ft_strncat_p(buffer, str, ft_strlen(str), list_buffer);
	*format_position += len;
	free(str);
}
