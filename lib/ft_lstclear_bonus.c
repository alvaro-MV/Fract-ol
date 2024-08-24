/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:23:26 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 15:36:07 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*holder;
	t_list	*list;

	list = *lst;
	while (list != NULL)
	{
		holder = list;
		list = list->next;
		del(holder->content);
		free(holder);
	}
	*lst = NULL;
}
