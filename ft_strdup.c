/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:02:44 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:02:51 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*ans;
	const size_t	len = ft_strlen(s) + 1;

	ans = (char *)malloc(len);
	if (!ans)
		return (0);
	return ((char *)ft_memcpy(ans, s, len));
}
