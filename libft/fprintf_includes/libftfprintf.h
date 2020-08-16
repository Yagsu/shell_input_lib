/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:32:35 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 18:53:35 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTFPRINTF_H
# define LIBFTFPRINTF_H

typedef struct				s_fbuffer
{
	int32_t					totallength;
	int32_t					curlength;
	char					*base_addr;
	int32_t					fd;
}							t_fbuffer;

void						printconversion_fd(char buffer[],
							const char **format_position, va_list arglist,
							t_fbuffer *list_buffer);
void						printbuffer_fd(t_fbuffer *buffer);
void						flushbuffer_fd(t_fbuffer *buffer);
char						*ft_strcat_fd(char *dest, const char *src,
							t_fbuffer *buffer);
char						*ft_strncat_fd(char *dest, const char *src,
							size_t n, t_fbuffer *buffer);
void						invalid_type_fd(const char **format_position, \
							char buffer[], t_fbuffer *list_buffer);
t_info						*getstruct_fd(const char **format_position, \
							t_fbuffer *buffer, va_list arglist);

#endif
