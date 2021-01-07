/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:10:58 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 18:00:20 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned char	hastab[128];
	size_t			len;
	char			*ans;

	if (!s1)
		return (0);
	if (!set || !*set)
		return (ft_strdup(s1));
	ft_bzero(hastab, 128);
	while (*set)
		hastab[(unsigned char)*set++] = 1;
	while (*s1 && hastab[(unsigned char)*s1])
		s1++;
	len = ft_strlen(s1);
	if (len--)
		while (hastab[(unsigned char)*(s1 + len)])
			len--;
	++len;
	if (!(ans = (char *)malloc(len + 1)))
		return (0);
	ft_memcpy(ans, s1, len);
	ans[len] = 0;
	return (ans);
}
