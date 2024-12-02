/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:03:48 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 14:56:53 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

// int	main()
// {
// 	char	buffer_re[] = "ABCDEFG";
// 	char	*ptr;
// 	printf("buffer_re: %s\n", ft_memset(buffer_re, 45, 6));
// 	ptr = buffer_re;
// 	printf("buffer_or: %s\n", memset(ptr, 45, 6));
// }
/*
 * Casos límite: definir dos char [], no lo replica bien.
 *
 * Casos límite: 0, < 0, máxima memoria.
 *
 *
*/
