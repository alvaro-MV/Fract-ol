/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:04:11 by alvmoral          #+#    #+#             */
/*   Updated: 2024/08/16 17:10:41 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = (char) c;
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if (*s == c)
		return ((char *) s);
	else
		return (0);
}

// int main()
// {
//     const char s[] = "HOLLLa";
//     printf("str: %s\n", ft_strchr(s, 'O'));
//     printf("str: %s\n", strchr(s, 'O'));
// }
