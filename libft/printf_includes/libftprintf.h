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

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>

# define BUFF_SIZE 1028
# define INT 1
# define UINT 2
# define FLOAT 3
# define OCTAL 4
# define STRING 5
# define CHAR 6
# define PTR 7
# define LOW_HEX 8
# define UP_HEX 9
# define PRCNT 10
# define ABC 11

typedef struct				s_buffer
{
	int32_t					totallength;
	int32_t					curlength;
	char					*base_addr;
}							t_buffer;

typedef struct				s_info
{
	t_buffer				*buffer_base;
	int32_t					flagzero;
	int32_t					flagminus;
	int32_t					flagplus;
	int32_t					flaghash;
	int32_t					flagspace;
	int32_t					padtotal;
	int32_t					fieldwidth;
	int32_t					prtotal;
	int32_t					is_zero;
	int32_t					is_long;
	int32_t					is_long_long;
	int32_t					is_short;
	int32_t					is_char;
	int32_t					is_null;
	int32_t					is_long_float;
	int32_t					type;
	char					*signstr;
	char					*hextag;
}							t_info;

typedef char				*t_printf_func(t_info *pt_list, va_list arglist);
typedef struct				s_funcs
{
	char					*name;
	int						type;
	t_printf_func			*fn_ptr;
}							t_funcs;

int							is_notsc(t_info *pt_list);
int							is_hex(t_info *pt_list);
char						*ft_strncat_p(char *dest, const char *src,
							size_t n, t_buffer *buffer);
char						*ft_strjoin_p(char const *s1, char *s2);
char						*ft_strcat_p(char *dest, const char *src,
							t_buffer *buffer);
char						*ft_strtrim_p(char const *s);
void						printconversion(char buffer[],
							const char **format_position, va_list arglist,
							t_buffer *list_buffer);
void						printbuffer(t_buffer *buffer);
void						flushbuffer(t_buffer *buffer);
void						gettype(t_info *info,
							const char **format_position);
char						*handleflag(t_info *pt_list, char *retstr);
void						plus_flag(t_info *pt_list, char **s);
void						plus_flag_float(t_info *pt_list, char **s);
void						zero_plus(t_info *pt_list, char **s);
void						zero_plus_float(t_info *pt_list, char **s);
void						handle_hextag(t_info *pt_list, char **s);
void						pad_space(t_info *pt_list, char **s);
t_info						*initstruct(t_buffer *buffer);
t_info						*getstruct(const char **format_position,
							t_buffer *buffer, va_list arglist);
void						getflag(t_info *info,
							const char **format_position);
void						hex_width(t_info *pt_list, char **s);
void						getwidthprecision(t_info *info,
							const char **format_position, va_list arglist);
void						checklong(t_info *info,
							const char **format_position);
void						checkshort(t_info *info,
							const char **format_position);
int							checkconversion(t_info *info,
							const char **format_position);
int							gettypedigit(const char **format_position);
int							gettypecs(const char **format_position);
int							istypeint(t_info *pt_list);
void						invalid_type(const char **format_position,
							char buffer[], t_buffer *s_buffer);
int							get_number(const char **format_position);
char						*getintwidth(t_info *pt_list, char *resstr);
int							getactualpad(t_info *pt_list, char *str);
char						*getresstr(t_info *pt_list, va_list arglist);
char						*getpadstr(t_info *pt_list, char *resstr);
char						*joinrespad(t_info *pt_list, char *resstr,
							char *padstr);
char						*parsestr(t_info *pt_list, va_list arglist);
char						*parseint(t_info *pt_list, va_list arglist);
char						*parsechar(t_info *pt_list, va_list arglist);
char						*parseptr(t_info *pt_list, va_list arglist);
char						*parsehex(t_info *pt_list, va_list arglist);
char						*parseuint(t_info *pt_list, va_list arglist);
char						*parseoctal(t_info *pt_list, va_list arglist);
char						*parseabc(t_info *pt_list, va_list arglist);
char						*parseprcnt(t_info *pt_list, va_list arglist);
char						*parsefloat(t_info *pt_list, va_list arglist);
char						*ftoa(double db, char *str, int prec);
char						*ftoa_long(long double db, char *str, int prec);
long long unsigned int		getnblonguint(t_info *pt_list, va_list arglist);
unsigned int				getnumberuint(t_info *pt_list, va_list arglist);
long long int				getnumberlong(t_info *pt_list, va_list arglist);
int							getnumber(t_info *pt_list, va_list arglist);
int							inttostr(long int x, char *str, int d);
int							nb_size(int nb);
int							nb_size_long(long long int nb);
void						reverse_str(char *str, int len);
void						append_hextag(t_info *pt_list, char **str);
char						*get_hex_str(t_info *pt_list, va_list arglist);
int							getindex(int type);
char						*appendresult(t_info *info, va_list arglist);

#endif
