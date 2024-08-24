/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:56:38 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/04 20:29:13 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	str = (char *) malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

//char addOne(unsigned int i, char c) {return (i + c);}

//int	main()
//{
	//char const s[] = ""; // ""
	//char	*ptr;

	//ptr = ft_strmapi(s, addOne);
	//printf("ptr: %s", ptr);
	//free(ptr);
//}

// Una varaible función se define igual que cualquier otra variable, 
//solo que también hay que incluir el tipo de parámetros. 
//Luego puedes pasarle cualquier
// función que tenga los parámetros indicados. 
