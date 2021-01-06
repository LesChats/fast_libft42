/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:04:37 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:04:45 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*ans;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (!(ans = malloc(len + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		ans[i] = (*f)((unsigned int)i, s[i]);
		++i;
	}
	ans[i] = 0;
	return (ans);
}
