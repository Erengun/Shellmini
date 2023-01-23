/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:09:50 by okarakel          #+#    #+#             */
/*   Updated: 2022/01/10 18:33:06 by okarakel         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		sub = malloc(1);
		sub[0] = 0;
		return (sub);
	}
	else if (len > ft_strlen(s))
		sub = malloc(ft_strlen(s));
	else
		sub = malloc(len + 1);
	if (!sub)
		return (0);
	i = -1;
	while (s[++i])
	{
		if (i >= start && i - start < len)
			sub[i - start] = s[i];
	}
	sub[len] = 0;
	return (sub);
}
