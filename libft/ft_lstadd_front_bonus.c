/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:26:43 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/05 21:20:03 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*list;

	list = *lst;
	new->next = list;
	*lst = new;
}
//int	main()
//{
	//t_list	new = (t_list) {"c", NULL};
	//t_list	*list = ft_lstnew("Hola");
	//ft_lstadd_front(&list, &new);
	//printf("conte: %s\n", (char *) new.content);
	//printf("next: %s\n", (char *) new.next->content);	
	//free(list);
//}