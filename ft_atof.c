/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:30:43 by alvmoral          #+#    #+#             */
/*   Updated: 2024/12/02 19:48:57 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calc_decimal(double *value, char *str)
{
	double	dec_idx;

	dec_idx = 10;
	while (*str >= '0' && *str <= '9')
	{
		*value = *value + (*str - '0') / dec_idx;
		dec_idx *= 10;
		str++;
	}
}

double	ft_atof(char *str)
{
	int		signo;
	double	value;

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
	if (*str++ == '.')
		calc_decimal(&value, str);
	if (signo % 2 != 0)
		value *= -1;
	return (value);
}
