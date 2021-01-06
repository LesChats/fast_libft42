/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:42:07 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/06 11:15:36 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (0);
	if (start + len > s_len)
		len = s_len - start;
	ans = (char *)malloc(len + 1);
	if (!ans)
		return (0);
	*(ans + len) = '\0';
	ft_memcpy(ans, s + start, len);
	return (ans);
}
