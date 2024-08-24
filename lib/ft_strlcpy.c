/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:31:28 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 14:31:29 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	tlen;
	size_t	i;

	i = 0;
	tlen = ft_strlen(src);
	if (dstsize != 0)
	{
		while (i < dstsize -1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (tlen);
}

// int	main(void)
// {
// 	char		dst[] = "AAAAAAAAAA";
// 	char		dstp[] = "AAAAAAAAAA";
// 	char const	src[] = "coucou";
// 	int			dstsize = 8;

// 	// printf("blen: %zu \t dst: %s\n", strlcpy(dst, src, -1), dst);
// 	printf("blen: %zu \t dst: %s\n", ft_strlcpy(dstp, src, -1), dstp);
// 	printf("logic: %d", !strcmp(src, dstp) && dst[strlen(src) + 1] == 'A');
// }
