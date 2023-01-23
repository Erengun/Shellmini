/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:00:52 by okarakel          #+#    #+#             */
/*   Updated: 2023/01/23 18:46:22 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
		c += ft_putchar_fd(s[i++], fd);
	c += (int)write(fd, "\n", 1);
	return (c);
}
