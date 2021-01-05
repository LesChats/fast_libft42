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

static void	recursive_clear(t_list **lst, void (*del)(void *))
{
	if (!*lst)
		return ;
	recursive_clear(&((*lst)->next), del);
	(*del)((*lst)->content);
	free(*lst);
}

static void	recursive_cl(t_list **lst)
{
	if (!*lst)
		return ;
	recursive_cl(&((*lst)->next));
	free(*lst);
}

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		recursive_clear(lst, del);
	else
		recursive_cl(lst);
	*lst = NULL;
}
