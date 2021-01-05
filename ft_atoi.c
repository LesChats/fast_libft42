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

int	ft_atoi(const char *str)
{
	unsigned char	c;
	long int		res;

	res = 0;
	while (((*str) == ' ' || (*str) == '\t' || (*str) == '\n' ||
		(*str) == '\v' || (*str) == '\f' || (*str) == '\r'))
		str++;
	if (*str == '-')
	{
		str++;
		while (*str)
			if ((c = *str++ - '0') > 9)
				return ((int)res);
			else
				res = (res << 1) + (res << 3) - c;
	}
	else if (*str == '+')
		str++;
	while (*str)
		if ((c = *str++ - '0') > 9)
			return ((int)res);
		else
			res = (res << 1) + (res << 3) + c;
	return ((int)res);
}
