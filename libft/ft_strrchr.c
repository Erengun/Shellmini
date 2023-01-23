/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:09:32 by okarakel          #+#    #+#             */
/*   Updated: 2022/01/08 18:21:47 by okarakel         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	int		i;

	a = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			a = (char *)s + i;
		i++;
	}
	if (s[i] == (char) c)
		a = (char *)s + i;
	return (a);
}
