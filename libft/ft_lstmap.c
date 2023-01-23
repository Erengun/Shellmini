/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:38:41 by okarakel          #+#    #+#             */
/*   Updated: 2022/01/10 19:33:36 by okarakel         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*s;

	if (!f || !lst)
		return (0);
	t = ft_lstnew(f(lst->content));
	if (!t)
		return (0);
	s = t;
	lst = lst->next;
	while (lst != NULL)
	{
		t->next = ft_lstnew(f(lst->content));
		if (!t->next)
		{
			ft_lstclear(&s, del);
			return (0);
		}
		lst = lst->next;
		t = t->next;
	}
	t->next = NULL;
	return (s);
}
