/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <omerlutfu.k34@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:59:12 by okarakel          #+#    #+#             */
/*   Updated: 2022/01/19 15:28:42 by okarakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c <= 0)
	{
		i = 1;
	}
	while (c)
	{
		i++;
		c = c / 10;
		if (c == 0)
			break ;
	}
	return (i);
}

static char	*sayiyapici(int n, int struzunluk, int rakam, char *str)
{
	while (struzunluk >= 0)
	{
		rakam = n % 10;
		str[struzunluk--] = rakam + 48;
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		struzunlugumuz;
	char	*str;
	int		rakamimiz;
	int		sign;

	struzunlugumuz = intlen(n);
	rakamimiz = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * struzunlugumuz + 1);
	if (!str)
		return (0);
	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	str[struzunlugumuz--] = '\0';
	sayiyapici(n, struzunlugumuz, rakamimiz, str);
	if (sign == -1 && str[0] == '0')
		str[0] = '-';
	return (str);
}
