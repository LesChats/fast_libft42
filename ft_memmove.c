/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:07:31 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:07:38 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	wordcopy(t_op *dstp, t_op *srcp, size_t len)
{
	t_op a0;
	t_op a1;

	if (len & 1)
	{
		*srcp -= OPSIZ;
		*dstp -= OPSIZ;
		((t_op *)*dstp)[0] = ((t_op *)*srcp)[0];
		if (len == 1)
			return ;
		--len;
	}
	while (len)
	{
		*srcp -= 16;
		*dstp -= 16;
		a1 = ((t_op *)*srcp)[1];
		a0 = ((t_op *)*srcp)[0];
		((t_op *)*dstp)[1] = a1;
		((t_op *)*dstp)[0] = a0;
		len -= 2;
	}
}

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	t_op		dstp;
	t_op		srcp;

	if (dest == src)
		return ((void *)src);
	if ((size_t)(dest - src) >= n)
		return ((dest = ft_memcpy(dest, src, n)));
	dstp = (t_op)dest;
	srcp = (t_op)src;
	srcp += n;
	dstp += n;
	if (n >= OPSIZ)
	{
		wordcopy(&dstp, &srcp, n >> 3);
		n &= 7;
	}
	while (n--)
		*(unsigned char *)(--dstp) = *(unsigned char *)(--srcp);
	return (dest);
}
