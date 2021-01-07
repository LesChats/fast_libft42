/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:03:25 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/06 11:58:40 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**size_t			ft_strlcat(char *dst, const char *src, size_t size)
**{
**	const size_t	dst_len = ft_strlen(dst);
**	const size_t	src_len = ft_strlen(src);
**	t_op			*srcp;
**	t_op			*dstp;
**	t_tuple			byte;
**
**	if (size <= dst_len)
**		return (src_len + size);
**	size -= dst_len;
**	srcp = (t_op *)src;
**	dstp = (t_op *)(dst + dst_len);
**	while (size >= OPSIZ)
**	{
**		if ((*srcp - LOMAGIC) & ~(*srcp) & HIMAGIC)
**			break ;
**		*dstp++ = *srcp++;
**		size -= OPSIZ;
**	}
**	byte.d = (char *)dstp;
**	byte.s = (const char *)srcp;
**	while (*byte.s && --size)
**		*byte.d++ = *byte.s++;
**	*byte.d = 0;
**	return (dst_len + src_len);
**}
*/

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	const char	*s_orig = s;

	while (*s && maxlen > 0)
	{
		s++;
		maxlen--;
	}
	return ((size_t)s - (size_t)s_orig);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;

	if (!dst && src && size == 0)
		return (ft_strlen(src));
	dst_len = ft_strnlen(dst, size);
	if (size <= dst_len)
		return (ft_strlen((char *)src) + size);
	while (size && *dst)
	{
		size--;
		dst++;
	}
	ft_strlcpy(dst, src, size);
	return (ft_strlen((char *)src) + dst_len);
}
