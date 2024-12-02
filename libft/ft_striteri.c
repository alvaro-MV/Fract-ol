/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:47:12 by alvmoral          #+#    #+#             */
/*   Updated: 2024/03/27 01:02:37 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	unsigned int		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// char	rot_r(unsigned int r, char *c)
// {
// 	if ((int) r + *c < 255)
// 		*c += r;
// }

// int	main()
// {
// 	char const s[] = "Hola";
// 	char	*ptr;

// 	ptr = ft_strmapi(s, rot_r);
// 	printf("ptr: %s", ptr);
// 	free(ptr);
// }	
