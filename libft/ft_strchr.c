/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:00:47 by okarakel          #+#    #+#             */
/*   Updated: 2022/01/08 18:21:09 by okarakel         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*st;

	st = (char *) s;
	i = 0;
	while (st[i])
	{
		if (st[i] == (char)c)
			return (st + i);
		i++;
	}
	if ((char) c == st[i])
		return (st + i);
	return (0);
}
