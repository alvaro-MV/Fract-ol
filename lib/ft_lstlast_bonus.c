/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:27:28 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/05 21:23:52 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*holder;

	holder = NULL;
	while (lst != NULL)
	{
		holder = lst;
		lst = lst->next;
	}
	return (holder);
}

//int	main(void)
//{
	//t_list	*new = &(t_list) {NULL, NULL};
	//t_list	*after = &(t_list) {NULL, NULL};
	//t_list	*list = &(t_list) {NULL, NULL};
	//double	val = 12.3;
	//list->content = (void *) &val;

	//ft_lstadd_front(&list, new);
	//ft_lstadd_front(&after, list);
	//ft_lstlast(new)->content = &val;
	//printf("contenido_last: %f\n", *(double *) ft_lstlast(new)->content);
//}