/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 01:18:35 by jesse             #+#    #+#             */
/*   Updated: 2020/07/09 01:18:51 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "libftsnprintf.h"

char		*alloc_data(char *res_buf, int res_len, int cur_len)
{
	char *d;

	d = (char *)malloc(sizeof(char) * (res_len + cur_len + 1));
	ft_bzero(d, res_len + cur_len + 1);
	if (res_len > 0)
		ft_memcpy(d, res_buf, res_len);
	return (d);
}

void		ft_append(t_snbuffer *buffer)
{
	char *new;

	new = alloc_data(*(buffer->res_buf), buffer->res_len, buffer->curlength);
	ft_memcpy(&new[buffer->res_len], buffer->base_addr, buffer->curlength);
	free(*(buffer->res_buf));
	*(buffer->res_buf) = new;
	buffer->res_len += buffer->curlength;
}
