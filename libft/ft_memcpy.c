/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:41:45 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 14:56:26 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptrdst = (unsigned char *) dst;
	ptrsrc = (unsigned char *) src;
	i = 0;
	while (n--)
	{
		ptrdst[i] = ptrsrc[i];
		i++;
	}
	return (ptrdst);
}

// int	main()
// {
// 	// char	dst[20] = "Hola";
// 	// char	src[20] = "Adios.";
// 	float	dst = 9;
// 	float	src = 2;

// 	ft_memcpy(&dst, &src, 1);
// 	printf("dst: %f\n", dst);
// 	memcpy(&dst, &src, sizeof(dst));
// 	printf("fun: %f\n", dst);

// }

/*
Si n vale cualquier otra cosa 
y es un puntero nulo (void *),
 da segmentation fault. Controla ese caso.
*/

/*
 * Probar para structs.
 *
 * Para arrays, para ints.
 *
 * Comprobar que no se solapan.
 *
 * si se cortan cuando n = 0.
 *
 * probar para overlapping.
 */
