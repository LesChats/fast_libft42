/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:10:43 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 18:00:37 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *found;
	const char *p;

	c = (t_byte)c;
	if (c == 0)
		return (ft_strchr(s, '\0'));
	found = NULL;
	while ((p = ft_strchr(s, c)))
	{
		found = p;
		s = p + 1;
	}
	return ((char *)found);
}
