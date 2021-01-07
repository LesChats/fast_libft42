/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:15:03 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 17:54:48 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear_whit_data(t_list **lst, void (*del)(void *))
{
	if (!*lst)
		return ;
	clear_whit_data(&((*lst)->next), del);
	(*del)((*lst)->content);
	free(*lst);
}

static void	clear_only_lst(t_list **lst)
{
	if (!*lst)
		return ;
	clear_only_lst(&((*lst)->next));
	free(*lst);
}

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		clear_whit_data(lst, del);
	else
		clear_only_lst(lst);
	*lst = NULL;
}
