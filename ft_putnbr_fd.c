/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:27:37 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/06 11:59:35 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		buf[12];
	long int	tmp;
	size_t		i;

	if (fd < 0)
		return ;
	tmp = (long int)n;
	if (n < 0)
		tmp = -tmp;
	i = 11;
	buf[11] = 0;
	if (tmp == 0)
		buf[--i] = '0';
	while (tmp)
	{
		buf[--i] = '0' + (tmp % 10);
		tmp /= 10;
	}
	if (n < 0)
		buf[--i] = '-';
	write(fd, buf + i, 11 - i);
}
