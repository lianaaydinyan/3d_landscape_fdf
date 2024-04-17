/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:49:26 by liaydiny          #+#    #+#             */
/*   Updated: 2023/02/15 19:50:14 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*s;
	t_list	*lop;

	s = *lst;
	while (*lst != NULL)
	{
		lop = *lst;
		del((*lst)->content);
		(*lst) = (*lst)->next;
		if (lop != s)
			free(lop);
	}
	s->next = NULL;
	free(*lst);
}
