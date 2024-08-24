/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:15:35 by alvmoral          #+#    #+#             */
/*   Updated: 2024/07/06 21:07:35 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_chtoa_w(unsigned int c)
{
	int	counter;

	counter = write(1, &c, 1);
	return (counter);
}
