/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:26:51 by okarakel          #+#    #+#             */
/*   Updated: 2022/01/07 18:25:24 by okarakel         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*adr;

	adr = malloc(count * size);
	if (adr == 0)
		return (0);
	ft_bzero(adr, size * count);
	return (adr);
}
