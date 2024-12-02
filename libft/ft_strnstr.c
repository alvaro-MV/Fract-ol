/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:31:44 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 14:58:49 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		count;
	int		j;

	count = 0;
	while (needle[count])
		count++;
	if (count == 0)
		return ((char *) haystack);
	i = 0;
	j = 0;
	while (haystack[i] && len)
	{
		while ((needle[j] == haystack[i + j]) && len - j)
		{
			if (j + 1 == count)
				return ((char *)(haystack + i));
			j++;
		}
		j = 0;
		i++;
		len--;
	}
	return (0);
}

// int	main()
// {
// 	char	str[] = "AAAAAAAAA";
// 	///char	to_find[] = "ly";
// 	printf("mine: %s\n", ft_strnstr(str, str, ft_strlen(str)));
// 	printf("orig: %s", strnstr(str, str, ft_strlen(str)));
// }
