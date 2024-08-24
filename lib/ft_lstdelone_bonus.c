/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:26:54 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 15:32:42 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

void	del(void *content)
{
	free(content);
}

//int	main()
//{
	//t_list	*new = ft_lstnew(NULL);
	//t_list	*after = ft_lstnew(NULL);
	//t_list	*list = ft_lstnew(NULL);
	//double	val = 12.3;

	//ft_lstadd_front(&list, new);
	//after->content = (void *) &val;
	//ft_lstadd_back(&new, after);
	//ft_lstdelone(after, del);
	//printf("contenido_last: %f\n", *(double *) ft_lstlast(new)->content);
	//free(new);
	//free(after);
	//free(list);
//}

/*
A ti te pasan el nodo a liberar y tu
lo que tienes que hacer es pasarle la funcion
del que lo libera.

Si no alocas memoria para content, te da:
free(): invalid pointer
Aborted.

Además, como solo está permitida la función
free(), se asume que la alocaci'on ha de 
hacerse en las otras funciones.
*/