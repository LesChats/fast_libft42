/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:06:16 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:06:20 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	t_op			lw;
	t_op			rep_c;

	rep_c = c | (c << 8);
	rep_c |= rep_c << 16;
	rep_c |= rep_c << 32;
	while (n >= OPSIZ)
	{
		lw = *(t_op *)s ^ rep_c;
		if ((lw - LOMAGIC) & ~lw & HIMAGIC)
			break ;
		n -= OPSIZ;
		s += OPSIZ;
	}
	while (n--)
		if (*(t_byte *)s++ == (t_byte)c)
			return ((void *)s - 1);
	return (NULL);
}
