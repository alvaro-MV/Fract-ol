/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:38:56 by alvmoral          #+#    #+#             */
/*   Updated: 2024/07/06 21:08:00 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_strtoa_w(char *str)
{
	int		counter;

	counter = 0;
	if (str == 0)
		return (write (1, "(null)", 6));
	while (*str)
		counter += write(1, str++, 1);
	return (counter);
}
