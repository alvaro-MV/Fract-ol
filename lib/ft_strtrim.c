/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:55:29 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/04 16:52:38 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static unsigned char	*startcmp(const char *s1, const char *set)
{
	int				i;
	unsigned char	*ptrs1;

	i = 0;
	ptrs1 = (unsigned char *) s1;
	while (ptrs1[i])
	{
		if (ft_strchr(set, ptrs1[i]) == NULL)
			return (&ptrs1[i]);
		i++;
	}
	return (&ptrs1[i]);
}

static int	fin_cmp(unsigned char *ptrs1, const char *set)
{
	int	i;
	int	len_s1;

	len_s1 = ft_strlen((char *) ptrs1);
	i = 0;
	while (len_s1 > 0 && ptrs1[len_s1 - 1])
	{
		if (ft_strchr(set, ptrs1[len_s1 - i]) == NULL)
			return (len_s1 - i + 1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				end;
	unsigned char	*ptrs1;
	char			*ptr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	ptrs1 = startcmp(s1, set);
	end = fin_cmp(ptrs1, set);
	ptr = (char *) malloc(end * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, ptrs1, end);
	ptr[end] = '\0';
	return (ptr);
}

// int	main()
// {
// 	const char	s1[] = "abcdba";
// 	const char	set[] = "acb"; //zsx, '\0' 
// 	char	*ptr;

// 	ptr = ft_strtrim(s1, set);
// 	printf("%s\n", ptr);
// 	free(ptr);	
// }
