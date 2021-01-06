/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:18:23 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 15:18:32 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *lstnew;

	if (!(lstnew = (t_list *)malloc(sizeof(t_list))))
		return ((void *)0);
	lstnew->content = content;
	lstnew->next = ((void *)0);
	return (lstnew);
}
