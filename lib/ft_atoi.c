/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:54:02 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/01 13:22:48 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_atoi(const char *str)
{
	int	signo;
	int	value;

	value = 0;
	signo = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signo++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = (*str - '0') + value * 10;
		str++;
	}
	if (signo % 2 != 0)
		value *= -1;
	return (value);
}

// int main()
// {
//     printf("mine: %i\n", ft_atoi("\n\t-21m34"));
//     printf("atoi: %i", atoi("\n\t-21m34"));
//     return (0);
// }