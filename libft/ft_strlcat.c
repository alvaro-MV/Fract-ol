/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:30:47 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 14:30:48 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		tlen;
	size_t		catlen;
	size_t		i;

	i = 0;
	tlen = ft_strlen((const char *) dst) + ft_strlen(src);
	catlen = dstsize - ft_strlen((const char *) dst) - 1;
	while (*dst)
		dst++;
	if (tlen - ft_strlen(src) >= dstsize)
		return (dstsize + ft_strlen(src));
	if (catlen > ft_strlen(src))
		catlen = ft_strlen(src);
	while (i < catlen)
	{
		*dst = src[i];
		i++;
		dst++;
	}
	*dst = '\0';
	return (tlen);
}

// int main()
// {
// 	char	dstm[34] = "Hola";
// 	// char    dsto[4] = "B";	
//     // char    src[] = "esto";
// 	printf("len_mine: %zu\t mine_str: %s\n",
// 		ft_strlcat(dstm, "abcd", -1), dstm);
// }

/*
Dice en el man que en principio no hay que contemplar la posibilidad
de que dst sea mayor que dstsize; tambien que si dstsize es 0,
entonces no hace falta hacer el NUl ter, porque no se concatena nada.
*/