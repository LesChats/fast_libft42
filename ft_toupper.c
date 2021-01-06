/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:43:54 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 17:45:30 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	c += (((96 - c) & (c - 123)) >> 9) & (-32);
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
