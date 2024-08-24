/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:58:49 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 14:56:31 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static int	set_index(size_t *i, size_t *j, size_t len, int diff)
{
	int	flag;

	if (diff <= 0)
	{
		flag = 1;
		*i = 0;
		*j = 0;
	}
	else
	{
		flag = 0;
		*i = len -1;
		*j = len -1;
	}
	return (flag);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;
	size_t	i;
	size_t	j;
	int		flag;

	if (dst == NULL && src == NULL)
		return (NULL);
	pdst = (char *) dst;
	psrc = (char *) src;
	flag = set_index(&i, &j, len, pdst - psrc);
	while (len--)
	{
		if (flag)
			pdst[i++] = psrc[j++];
		else
			pdst[i--] = psrc[j--];
	}
	return (dst);
}

// int	main(void)
// {
// 	char	dst[20] = "Hola";
// 	char	dsto[20] = "Hola";
// 	char	src[20] = "Adios.";
// 	float	dst = 60.344;
// 	float	dsto = 60.344;
// 	float	src = -123.76;

// 	ft_memmove(&dst, &src, 4);
// 	printf("dst: %f\n", dst);
// 	memmove(&dsto, &src, 4);
// 	printf("fun: %f\n", dsto);
// 	return (0);
// }