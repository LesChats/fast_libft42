/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:10:25 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:10:34 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*small(const char *big, const char *little, size_t len, size_t n)
{
	while (*big && len-- >= n)
	{
		if (!ft_strncmp(big, little, n))
			return ((char *)big);
		big++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	size_t	tmp;
	const char *sav;

	sav = big;
	if (!(n = ft_strlen(little)))
		return ((char *)sav);
	if (len <  0x40)
		return (small(big, little, len, n));
	big = ft_strchr(big, *little);
	tmp = (size_t)(big - sav);
	if (!big || tmp > len)
		return (NULL);
	len -= tmp;
	while (len >= n && *big)
	{
		if (!ft_strncmp(big + 1, little + 1, n - 1))
			return ((char *)big);
		sav = ++big;
		big = ft_strchr(big, *little);
		tmp = (size_t)(big - sav);
		if (!big || tmp > len)
			return (NULL);
		len -= tmp;
	}
	return (NULL);
}
