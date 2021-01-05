/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:03:01 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 18:00:02 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len; 
	size_t	s2_len; 	
	char	*ans;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ans = malloc(s1_len + s2_len + 1);
	if (!ans)
		return (0);
	ft_memcpy(ans, s1, s1_len);
	ft_memcpy(ans + s1_len, s2, s2_len);
	ans[s1_len + s2_len] = 0;
	return (ans);
}
