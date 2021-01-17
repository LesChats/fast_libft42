/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:09:50 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 17:59:07 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** need to thind better implementation
*/

char	*ft_strcpy(char *dest, const char *src)
{
	char * const d_sav = *dest;

	while ((*dest++ = *src++))
		;
	return (d_sav); 
}
