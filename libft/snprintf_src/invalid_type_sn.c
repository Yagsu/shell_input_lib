/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_type_sn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:19:54 by juuttera          #+#    #+#             */
/*   Updated: 2020/07/09 00:41:44 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "libftsnprintf.h"

void			invalid_type_sn(const char **format_position, char buffer[],
				t_snbuffer *list_buffer)
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
	ft_strncat_sn(buffer, str, ft_strlen(str), list_buffer);
	*format_position += len;
	free(str);
}
