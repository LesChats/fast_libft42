/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:07:12 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:07:16 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	wordcopy(t_op dstp, t_op srcp, size_t len)
{
	register t_op a0;
	register t_op a1;

	if (len & 1)
	{
		((t_op *)dstp)[0] = ((t_op *)srcp)[0];
		if (len == 1)
			return ;
		srcp += OPSIZ;
		dstp += OPSIZ;
		len -= 1;
	}
	while (len)
	{
		a0 = ((t_op *)srcp)[0];
		a1 = ((t_op *)srcp)[1];
		((t_op *)dstp)[0] = a0;
		((t_op *)dstp)[1] = a1;
		srcp += 2 * OPSIZ;
		dstp += 2 * OPSIZ;
		len -= 2;
	}
}

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_op	dstp;
	t_op	srcp;

	if (dest == src)
		return (dest);
	dstp = (t_op)dest;
	srcp = (t_op)src;
	if (n >= OP_T_THRES)
	{
		wordcopy(dstp, srcp, n / OPSIZ);
		srcp += n & -OPSIZ;
		dstp += n & -OPSIZ;
		n %= OPSIZ;
	}
	else if (n >= OPSIZ)
	{
		*(t_op *)dstp = *(t_op *)srcp;
		n -= OPSIZ;
		dstp += OPSIZ;
		srcp += OPSIZ;
	}
	while (n--)
		*(t_byte *)dstp++ = *(t_byte *)srcp++;
	return (dest);
}
