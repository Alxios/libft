/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:55:12 by agaspar           #+#    #+#             */
/*   Updated: 2015/11/30 11:07:20 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *list_last;

	list = f(lst);
	list_last = list;
	if (list == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		list_last->next = f(lst);
		if (list_last->next == NULL)
			return (NULL);
		list_last = list_last->next;
	}
	return (list);
}
