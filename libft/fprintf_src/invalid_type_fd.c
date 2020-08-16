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
#include "libftfprintf.h"

void			invalid_type_fd(const char **format_position, char buffer[],
				t_fbuffer *list_buffer)
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
	ft_strncat_fd(buffer, str, ft_strlen(str), list_buffer);
	*format_position += len;
	free(str);
}
