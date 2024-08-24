/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:09:27 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 14:52:23 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	ptr = (char *) malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, len + 1);
	return (ptr);
}

// int	main()
// {
// 	const char	s1[] = "HAHAHA \0 tu me vois pas !";
// 	const char	s2[] = "HAHAHA \0 tu me vois pas !";
// 	char		*ptrm = ft_strdup(s1);
// 	char		*ptro = strdup(s2);
// 	printf("ptrm: %s\n", ptrm);
// 	printf("ptro: %s\n", ptro);
// 	free(ptrm);
// 	free(ptro);
// }

/*
 * Buscar si el resultado de malloc puede ser null.
 *
 * Hacer el make para importar libft.h.
 */
