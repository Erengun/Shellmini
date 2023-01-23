/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <omerlutfu.k34@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:59:03 by okarakel          #+#    #+#             */
/*   Updated: 2022/01/19 15:30:30 by okarakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_special(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	ft_wordcounter(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	if (s[0] != c && s[0])
		count++;
	i = 1;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (0);
	str = malloc(ft_wordcounter(s, c) * sizeof(char *) + 1);
	if (!str)
		return (0);
	j = 0;
	i = 0;
	while ((s[i] && s[i - 1] && i > 0) || (i == 0))
	{
		if ((i > 0 && s[i] != c && s[i - 1] == c)
			|| (s[i] != c && s[i] && i == 0))
		{
			str[j] = malloc(ft_strlen_special(s + i, c) + 1);
			ft_strlcpy(str[j++], s + i, ft_strlen_special(s + i, c) + 1);
		}
		i++;
	}
	str[j] = (void *)0;
	return (str);
}
