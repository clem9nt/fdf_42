/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:39:23 by cvidon            #+#    #+#             */
/*   Updated: 2021/11/30 10:17:14 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	if (!del || !*lst)
		return ;
	prev = 0;
	while (*lst)
	{
		prev = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(prev);
	}
}
