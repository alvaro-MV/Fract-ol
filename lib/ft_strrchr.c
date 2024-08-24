/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:05:01 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 14:58:57 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*sh;

	sh = 0;
	c = (char) c;
	while (*s)
	{
		if (*s == c)
			sh = s;
		s++;
	}
	if (*s == c)
		return ((char *) s);
	else
		return ((char *) sh);
}

// int main()
// {
//     const char s[] = "HOLLLa";
//     printf("str: %s\n", ft_strrchr(s, 'z'));
//     printf("str: %s\n", strrchr(s, 'z'));
// }