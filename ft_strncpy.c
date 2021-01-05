/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:05:21 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 17:58:46 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	const size_t len = MIN(n, ft_strlen(src));

	if (len != n)
		ft_memset(dest + len, '\0', n - len);
	return (ft_memcpy(dest, src, n));
}
