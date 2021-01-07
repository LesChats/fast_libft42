/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:20:00 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/06 18:47:21 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_len(size_t x)
{
	if (x >= 1000000000)
		return (10);
	if (x >= 100000000)
		return (9);
	if (x >= 10000000)
		return (8);
	if (x >= 1000000)
		return (7);
	if (x >= 100000)
		return (6);
	if (x >= 10000)
		return (5);
	if (x >= 1000)
		return (4);
	if (x >= 100)
		return (3);
	if (x >= 10)
		return (2);
	return (1);
}

char	*ft_itoa(int n)
{
	size_t		len;
	size_t		nn;
	char		*ans;
	const char	signe = (n >> 31)

	nn = (size_t)(signe ? -(long int)n : n);
	len = (signe ? get_len(nn) + 2 : get_len(nn) + 1);
	if (!(ans = (char *)malloc(len)))
		return (0);
	ans += len;
	*--ans = 0;
	if (!nn)
		*--ans = '0';
	while (nn)
	{
		*--ans = '0' + (nn % 10);
		nn /= 10;
	}
	if (signe)
		*--ans = '-';
	return (ans);
}
