/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:03:51 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:04:03 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**size_t	ft_strlcpy(char *dst, const char *src, size_t size)
**{
**	t_op		*dstp;
**	t_op		*srcp;
**	char		*d;
**	const char	*s;
**
**	if (!dst || !src)
**		return (0);
**	if (size == 0)
**		return (ft_strlen(src));
**	dstp = (t_op *)dst;
**	srcp = (t_op *)src;
**	while (size >= OPSIZ)
**	{
**		if (((*srcp - LOMAGIC) & ~(*srcp) & HIMAGIC))
**			break ;
**		*dstp++ = *srcp++;
**		size -= OPSIZ;
**	}
**	d = (char *)dstp;
**	s = (const char *)srcp;
**	while (--size && *s)
**		*d++ = *s++;
**	*d = 0;
**	return ((size_t)(((s + ft_strlen(s))) - src));
**}
*/

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char *src_orig = src;

	if (!dst || !src)
		return (0);
	while (size > 1 && *src)
	{
		*dst = *src;
		size--;
		dst++;
		src++;
	}
	if (size != 0)
		*dst = '\0';
	while (*src)
		src++;
	return ((size_t)src - (size_t)src_orig);
}
