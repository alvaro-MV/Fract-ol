/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:27:57 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 15:31:55 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*first_node;

	if (lst == NULL || !f || !del)
		return (NULL);
	first_node = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(NULL);
		if (new_node == NULL)
		{
			ft_lstclear(&first_node, del);
			return (NULL);
		}
		new_node->content = f(lst->content);
		ft_lstadd_back(&first_node, new_node);
		lst = lst->next;
	}
	return (first_node);
}
