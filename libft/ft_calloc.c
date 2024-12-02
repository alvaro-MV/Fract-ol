/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:52:04 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 15:28:09 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && size && SIZE_MAX / count < size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
// int main()
// {

// 	// This pointer will hold the
// 	// base address of the block created
// 	char** ptr;
// 	int n, i;

// 	// Get the number of elements for the array
// 	n = 7;
// 	printf("Enter number of elements: %d\n", n);

// 	// Dynamically allocate memory using calloc()
// 	ptr = (char**)ft_calloc(n, 7);

// 	if (ptr == NULL) {
// 		printf("Memory not allocated.\n");
// 		exit(0);
// 	}
// 	else {
// 		for (i = 0; i < n; ++i) {
// 			ptr[i] = "Frente";
// 		}

// 		// Print the elements of the array
// 		printf("The elements of the array are: ");
// 		for (i = 0; i < n; ++i) {
// 			printf("%s, ", ptr[i]);
// 		}
// 		free(ptr);
// 	}

// 	return 0;
// }
