/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:38:18 by okarakel          #+#    #+#             */
/*   Updated: 2022/01/10 19:33:59 by okarakel         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ls;
	t_list	*a;

	ls = *lst;
	if (*lst == NULL)
		return ;
	a = ls;
	while (a != NULL)
	{
		ls = a;
		a = ls->next;
		del(ls->content);
		free(ls);
	}
	*lst = NULL;
}
