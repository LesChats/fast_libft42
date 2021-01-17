/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:06:39 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:06:41 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	find_diff(t_byte *s1, t_byte *s2)
{
	if (s1[0] != s2[0])
		return (s1[0] - s2[0]);
	if (s1[1] != s2[1])
		return (s1[1] - s2[1]);
	if (s1[2] != s2[2])
		return (s1[2] - s2[2]);
	if (s1[3] != s2[3])
		return (s1[3] - s2[3]);
	if (s1[4] != s2[4])
		return (s1[4] - s2[4]);
	if (s1[5] != s2[5])
		return (s1[5] - s2[5]);
	if (s1[6] != s2[6])
		return (s1[6] - s2[6]);
	return (s1[7] - s2[7]);
}

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_op		s1_p;
	t_op		s2_p;
	size_t		g_len;

	if (s1 == s2)
		return (0);
	s1_p = (t_op)s1;
	s2_p = (t_op)s2;
	g_len = n >> 3;
	while (g_len)
	{
		if (*(t_op *)s1_p != *(t_op *)s2_p)
			return (find_diff((t_byte *)s1_p, (t_byte *)s2_p));
		s1_p += OPSIZ;
		s2_p += OPSIZ;
		--g_len;
	}
	n &= 0b111;
	while (n)
	{
		if (*(t_byte *)s1_p++ != *(t_byte *)s2_p++)
			return (*(t_byte *)(s1_p - 1) - *(t_byte *)(s2_p - 1));
		--n;
	}
	return (0);
}
