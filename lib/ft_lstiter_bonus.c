/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:44:55 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 15:36:47 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	t_list	*holder;

	while (lst != NULL)
	{
		holder = lst;
		lst = lst->next;
		f(holder->content);
	}
}
