/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:17:55 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/11/09 16:04:06 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*expand_path(char *str, int i, int quotes[2])
{	
	char	*path;
	char	*aux;

	quotes[0] = 0;
	quotes[1] = 0;
	while (++i >= 0 && str && str[i])
	{
		quotes[0] = (quotes[0] + (!quotes[1] && str[i] == '\'')) % 2;
		quotes[1] = (quotes[1] + (!quotes[0] && str[i] == '\"')) % 2;
		if ((!quotes[0] && !quotes[1]) && ((str[i] == '~')))
		{
			aux = ft_substr(str, 0, i);
			path = ft_strjoin(aux, getenv("HOME"));
			free(aux);
			aux = ft_substr(str, i + 1, ft_strlen(str));
			i = i + ft_strlen(getenv("HOME")) - 1;
			free(str);
			str = ft_strjoin(path, aux);
			free(path);
			return (expand_path(str, i, quotes));
		}
	}
	return (str);
}

static char	*get_substr_vars(char *str, int len[3], int ij[2], int quotes[2])
{
	char	*var;
	char	*exp1;

	ij[0] = -1;
	while (++ij[0] >= 0 && str && str[ij[0]])
	{
		quotes[0] = (quotes[0] + (!quotes[1] && str[ij[0]] == '\'')) % 2;
		quotes[1] = (quotes[1] + (!quotes[0] && str[ij[0]] == '\"')) % 2;
		if ((!quotes[0] || quotes[1]) && ((str[ij[0]] == '$' && \
			ft_strchars_i(&str[ij[0] + 1], "\"\' ~$") && \
			str[ij[0] + 1] != '\0') || (!quotes[0] && !quotes[1] && \
			str[ij[0]] == '$' && ft_strchars_i("\"\'", &str[ij[0] + 1]) != -1)))
		{
			ij[1] = ft_strchars_i(&str[ij[0] + 1], "\"\' $");
			var = ft_substr(&str[ij[0] + 1], 0, ij[1]);
			exp1 = getenv(var);
			if (!exp1)
				exp1 = "";
			len[0] = len[0] - ft_strlen(var) - 1 + ft_strlen(exp1);
			len[2] = ft_strlen(var);
			free(var);
			return (exp1);
		}
	}
	return (NULL);
}

char	*expand_vars(char *str, int ij[2], int quotes[2])
{
	int		len[3];
	char	*exp1;
	char	*ptr;

	quotes[0] = 0;
	quotes[1] = 0;
	ij[0] = -1;
	ij[1] = -2;
	len[0] = ft_strlen(str);
	len[2] = 0;
	exp1 = get_substr_vars(str, len, ij, quotes);
	if (ij[1] == -2)
		return (str);
	ptr = ft_calloc(sizeof(char), (len[0] + 1));
	if (!ptr)
		return (NULL);
	ft_strlcat(ptr, str, ij[0] + 1);
	ft_strlcat(ptr, exp1, len[0] + 1);
	len[1] = ft_strlen(ptr);
	ft_strlcat(ptr, &str[ij[0] + len[2] + 1], len[0] + 1);
	free(str);
	ij[1] = len[1];
	return (expand_vars(ptr, ij, quotes));
}