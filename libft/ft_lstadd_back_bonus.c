/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:26:23 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/05 21:21:43 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;
	t_list	*holder;

	list = *lst;
	if (list == NULL)
		*lst = new;
	if (list != NULL)
	{
		while (list != NULL)
		{
			holder = list;
			list = list->next;
		}
		holder->next = new;
	}
}

// int	main(void)
// {
// 	t_list	*new = &(t_list) {NULL, NULL};
// 	//t_list	*after = &(t_list) {NULL, NULL};
// 	// t_list	*list = &(t_list) {NULL, NULL};
// 	//double	val = 12.3;

// 	//ft_lstadd_front(&list, (void *) 0);
// 	//after->content = (void *) &val;
// 	ft_lstadd_back(&new, (void *) 0);
// 	printf("contenido_last: %f\n", *(double *) ft_lstlast(new)->content);
// }
