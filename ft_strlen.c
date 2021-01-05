/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:04:16 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:04:26 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	byte_check(const char *cp, const char *s)
{
	if (!*cp)
		return (cp - s);
	if (!cp[1])
		return (cp - s + 1);
	if (!cp[2])
		return (cp - s + 2);
	if (!cp[3])
		return (cp - s + 3);
	if (!cp[4])
		return (cp - s + 4);
	if (!cp[5])
		return (cp - s + 5);
	if (!cp[6])
		return (cp - s + 6);
	if (!cp[7])
		return (cp - s + 7);
	return (0);
}

size_t					ft_strlen(const char *s)
{
	t_op		word;
	t_op		*s_ptr;
	size_t		ans;
	const char	*cpy;

	if (!*s)
		return (0);
	cpy = s;
	while ((t_op)cpy & 0b111)
		if (*cpy++ == 0)
			return (cpy - s - 1);
	s_ptr = (t_op *)cpy;
	while (1)
	{
		word = *s_ptr++;
		if (((word - LOMAGIC) & ~word & HIMAGIC))
			if ((ans = byte_check((const char *)(s_ptr - 1), s)))
				return (ans);
	}
}
