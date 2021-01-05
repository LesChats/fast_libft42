/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:07:51 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:07:55 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	loop(t_op *dstpp, t_op c, size_t len, size_t xlen)
{
	const t_op step = 8 * OPSIZ;

	while (len)
	{
		((t_op *)*dstpp)[0] = c;
		((t_op *)*dstpp)[1] = c;
		((t_op *)*dstpp)[2] = c;
		((t_op *)*dstpp)[3] = c;
		((t_op *)*dstpp)[4] = c;
		((t_op *)*dstpp)[5] = c;
		((t_op *)*dstpp)[6] = c;
		((t_op *)*dstpp)[7] = c;
		*dstpp += step;
		--len;
	}
	while (xlen)
	{
		*(t_op *)*dstpp = c;
		*dstpp += OPSIZ;
		--xlen;
	}
}

void				*ft_memset(void *s, int c, size_t n)
{
	t_op dstp;
	t_op cccc;

	dstp = (t_op)s;
	if (n >= 8)
	{
		cccc = (t_byte)c;
		cccc |= cccc << 8;
		cccc |= cccc << 16;
		cccc |= cccc << 32;
		loop(&dstp, cccc, n / (OPSIZ * 8), (n % (OPSIZ * 8)) / OPSIZ);
		n %= OPSIZ;
	}
	while (n--)
		*(t_byte *)dstp++ = c;
	return (s);
}
