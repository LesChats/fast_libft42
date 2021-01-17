/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:09:38 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/06 11:46:40 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**long int	find(const t_byte *s, int c)
**{
**	int i;
**
**	i = -1;
**	while (++i < 8)
**	{
**		if (s[i] == c)
**			return ((long int)s + i);
**		else if (!s[i])
**			return (0);
**	}
**	return (-1);
**}
**
**char		*ft_strchr(const char *s, int c)
**{
**	const t_byte	*s_ptr;
**	const t_op		*lg_ptr;
**	long int		ans;
**	t_op			charmask;
**	t_op			word;
**
**	s_ptr = (const t_byte *)s;
**	while ((t_op)s_ptr & 0b111)
**		if (*s_ptr++ == c)
**			return ((char *)(s_ptr - 1));
**		else if (*(s_ptr - 1) == '\0')
**			return (NULL);
**	lg_ptr = (const t_op *)s_ptr;
**	charmask = c | (c << 8);
**	charmask |= charmask << 16;
**	charmask |= charmask << 32;
**	while (1)
**	{
**		word = *lg_ptr++;
**		if (((word - LOMAGIC) & (~word) & HIMAGIC) ||
**		(((word ^ charmask) - LOMAGIC) & ~(word ^ charmask) & HIMAGIC))
**			if ((ans = find((const t_byte *)(lg_ptr - 1), c)) != -1)
**				return ((char *)ans);
**	}
**}
*/

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s != c && *s)
		++s;
	if (*s)
		return ((char *)s);
	return (0);
}
