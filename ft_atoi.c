/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:19:07 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:19:09 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** thank you MJ for improving the fist while check <3
*/

int	ft_atoi(const char *str)
{
	unsigned char	c;
	long int		res;

	res = 0;
	while (*str == ' ' || (unsigned)*str - '\t' < 5)
		++str;
	if (*str == '-')
	{
		++str;
		while (*str)
			if ((c = *str++ - '0') > 9)
				return ((int)res);
			else
				res = (res << 1) + (res << 3) - c;
	}
	else if (*str == '+')
		++str;
	while (*str)
		if ((c = *str++ - '0') > 9)
			return ((int)res);
		else
			res = (res << 1) + (res << 3) + c;
	return ((int)res);
}
