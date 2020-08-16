/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:40:40 by juuttera          #+#    #+#             */
/*   Updated: 2020/02/25 17:53:39 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static const t_funcs g_funclist[] =
{
	{"STRING", STRING, &parsestr},
	{"DIGIT", INT, &parseint},
	{"CHAR", CHAR, &parsechar},
	{"PTR", PTR, &parseptr},
	{"x_HEX", LOW_HEX, &parsehex},
	{"X_HEX", UP_HEX, &parsehex},
	{"UINT", UINT, &parseuint},
	{"OCTAL", OCTAL, &parseoctal},
	{"PRCNT", PRCNT, &parseprcnt},
	{"FLOAT", FLOAT, &parsefloat},
	{"ABC", ABC, &parseabc},
	{"NULL", 0, NULL}
};

int		getindex(int type)
{
	int	i;

	i = 0;
	while (g_funclist[i].type)
	{
		if (g_funclist[i].type == type)
			return (i);
		i++;
	}
	return (-1);
}

char	*getresstr(t_info *pt_list, va_list arglist)
{
	char	*res;
	char	*tmp;

	if (!(tmp = g_funclist[getindex(pt_list->type)].fn_ptr(pt_list, arglist)))
		return (NULL);
	if (pt_list->prtotal != -1 && pt_list->type == STRING)
		res = ft_strncpy(ft_strnew(pt_list->prtotal), tmp, pt_list->prtotal);
	else
		res = ft_strdup(tmp);
	if (istypeint(pt_list) || is_hex(pt_list))
		hex_width(pt_list, &res);
	if (pt_list->type != FLOAT)
		plus_flag(pt_list, &res);
	else
		plus_flag_float(pt_list, &res);
	if (is_hex(pt_list))
		append_hextag(pt_list, &res);
	free(tmp);
	return (res);
}

char	*getpadstr(t_info *pt_list, char *resstr)
{
	char	*padstr;
	int		actualpad;

	actualpad = getactualpad(pt_list, resstr);
	padstr = NULL;
	if (actualpad > 0)
	{
		if (pt_list->flagzero && !pt_list->flagminus &&
		((istypeint(pt_list) && pt_list->prtotal == -1) ||
		pt_list->type == FLOAT || is_hex(pt_list) || pt_list->type == PRCNT))
			padstr = ft_memset(ft_strnew(actualpad), '0', actualpad);
		else
			padstr = ft_memset(ft_strnew(actualpad), ' ', actualpad);
	}
	return (padstr);
}

char	*handleflag(t_info *pt_list, char *retstr)
{
	char	*done;

	done = ft_strdup(retstr);
	if (pt_list->type == FLOAT)
		zero_plus_float(pt_list, &done);
	else
		zero_plus(pt_list, &done);
	if (is_hex(pt_list))
		handle_hextag(pt_list, &done);
	pad_space(pt_list, &done);
	free(retstr);
	return (done);
}

char	*joinrespad(t_info *pt_list, char *resstr, char *padstr)
{
	char	*tmp;

	if (padstr == NULL)
	{
		tmp = ft_strdup(resstr);
		free(resstr);
		return (tmp);
	}
	if (!pt_list->flagminus)
		tmp = ft_strjoin(padstr, resstr);
	else
		tmp = ft_strjoin(resstr, padstr);
	free_n(2, resstr, padstr);
	return (tmp);
}
