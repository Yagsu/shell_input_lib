/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsnprintf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:32:35 by juuttera          #+#    #+#             */
/*   Updated: 2020/07/09 01:22:50 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSNPRINTF_H
# define LIBFTSNPRINTF_H

typedef struct				s_snbuffer
{
	int32_t					totallength;
	int32_t					curlength;
	char					*base_addr;
	char					**res_buf;
	int32_t					res_len;
}							t_snbuffer;

char						*alloc_data(char *res_buf, int res_len,
							int cur_len);
void						ft_append(t_snbuffer *buffer);
void						printconversion_sn(char buffer[],
							const char **format_position, va_list arglist,
							t_snbuffer *list_buffer);
void						printbuffer_sn(t_snbuffer *buffer);
void						flushbuffer_sn(t_snbuffer *buffer);
char						*ft_strcat_sn(char *dest, const char *src,
							t_snbuffer *buffer);
char						*ft_strncat_sn(char *dest, const char *src,
							size_t n, t_snbuffer *buffer);
void						invalid_type_sn(const char **format_position, \
							char buffer[], t_snbuffer *list_buffer);
t_info						*getstruct_sn(const char **format_position, \
							t_snbuffer *buffer, va_list arglist);

#endif
