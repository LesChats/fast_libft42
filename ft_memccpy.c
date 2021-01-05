/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:05:50 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:05:54 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	*find(void *dest, const void *src, t_byte c)
{
	if ((((t_byte *)dest)[0] = ((t_byte *)src)[0]) == c)
		return ((t_byte *)dest + 1);
	if ((((t_byte *)dest)[1] = ((t_byte *)src)[1]) == c)
		return ((t_byte *)dest + 2);
	if ((((t_byte *)dest)[2] = ((t_byte *)src)[2]) == c)
		return ((t_byte *)dest + 3);
	if ((((t_byte *)dest)[3] = ((t_byte *)src)[3]) == c)
		return ((t_byte *)dest + 4);
	if ((((t_byte *)dest)[4] = ((t_byte *)src)[4]) == c)
		return ((t_byte *)dest + 5);
	if ((((t_byte *)dest)[5] = ((t_byte *)src)[5]) == c)
		return ((t_byte *)dest + 6);
	if ((((t_byte *)dest)[6] = ((t_byte *)src)[6]) == c)
		return ((t_byte *)dest + 7);
	if ((((t_byte *)dest)[7] = ((t_byte *)src)[7]) == c)
		return ((t_byte *)dest + 8);
	return (dest);
}

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	t_op	cc;
	t_op	lw;

	c = (t_byte)c;
	while (n % OPSIZ && n--)
		if ((*(t_byte *)dest++ = *(t_byte *)src++) == c)
			return ((t_op *)dest);
	cc = c * LOMAGIC;
	while (n)
	{
		lw = *(t_op *)src ^ cc;
		if ((lw - LOMAGIC) & ~lw & HIMAGIC)
		{
			dest = find(dest, src, (t_byte)c);
			if (*(t_byte *)(dest - 1) == (t_byte)c)
				return ((t_op *)dest);
		}
		else
			*(t_op *)dest = *(t_op *)src;
		n -= OPSIZ;
		dest += OPSIZ;
		src += OPSIZ;
	}
	return (NULL);
}
