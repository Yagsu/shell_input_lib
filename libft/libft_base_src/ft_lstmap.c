/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juuttera <juuttera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:31:06 by juuttera          #+#    #+#             */
/*   Updated: 2019/10/24 15:43:20 by juuttera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*newlist;

	tmp = lst;
	while (tmp)
	{
		if (!newlist)
		{
			newlist = f(tmp);
			tmp2 = newlist;
		}
		else
		{
			newlist->next = f(tmp);
			newlist = newlist->next;
		}
		tmp = tmp->next;
	}
	return (tmp2);
}
