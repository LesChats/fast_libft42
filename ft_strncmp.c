/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:04:56 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:05:11 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**int	ft_strncmp(const char *s1, const char *s2, size_t n)
**{
**	t_op *a1;
**	t_op *a2;
**
**	if (!n)
**		return (0);
**	if (n >= OPSIZ)
**	{
**		a1 = (t_op *)s1;
**		a2 = (t_op *)s2;
**		while (n >= OPSIZ && *a1 == *a2)
**		{
**			n -= OPSIZ;
**			if (!n || ((*a1 - LOMAGIC) & ~(*a1) & HIMAGIC))
**				return (0);
**			a1++;
**			a2++;
**		}
**		s1 = (const char *)a1;
**		s2 = (const char *)a2;
**	}
**	while (n-- && *s1 == *s2++)
**		if (!n || !*s1++)
**			return (0);
**	return ((unsigned char)*s1 - (unsigned char)*(--s2));
**}
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s1 == *s2)
	{
		if (!--n || !*s1)
			return (0);
		++s1;
		++s2;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
