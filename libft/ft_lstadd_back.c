/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:39:15 by cvidon            #+#    #+#             */
/*   Updated: 2021/11/30 17:45:14 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*cpy;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	cpy = *alst;
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = new;
}
