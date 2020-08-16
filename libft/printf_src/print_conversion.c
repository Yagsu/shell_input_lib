/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 20:27:34 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:43:53 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int			nb_size(int nb)
{
	unsigned int	size;
	unsigned int	nbr;

	nbr = (unsigned int)nb;
	size = 0;
	if (nb < 0)
		size = size + 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		++size;
	}
	return (size + 1);
}

int			istypeint(t_info *pt_list)
{
	if (pt_list->type == INT || pt_list->type == UINT
	|| pt_list->type == FLOAT)
		return (1);
	else if (pt_list->type == OCTAL)
		return (1);
	return (0);
}

void		gettype(t_info *info, const char **format_position)
{
	if (**format_position == 'l' || **format_position == 'h'
	|| **format_position == 'L')
	{
		if (**format_position == 'h')
			checkshort(info, format_position);
		else if (**format_position == 'L')
		{
			info->is_long_float = 1;
			(*format_position)++;
		}
		else
			checklong(info, format_position);
	}
	checkconversion(info, format_position);
}

char		*appendresult(t_info *info, va_list arglist)
{
	char	*padstr;
	char	*resstr;
	char	*retstr;
	char	*done;

	if (!(resstr = getresstr(info, arglist)))
		return (NULL);
	padstr = getpadstr(info, resstr);
	retstr = joinrespad(info, resstr, padstr);
	done = handleflag(info, retstr);
	return (done);
}

void		printconversion(char buffer[], const char **format_position,
			va_list arglist, t_buffer *list_buffer)
{
	t_info	*info;
	char	*done;

	if (!(info = getstruct(format_position, list_buffer, arglist)))
		exit(0);
	if (!info->type)
	{
		invalid_type(format_position, buffer, list_buffer);
		return ;
	}
	done = appendresult(info, arglist);
	if (!(done))
		return ;
	ft_strncat_p(buffer, done, ft_strlen(done), list_buffer);
	free_n(2, done, info);
}
