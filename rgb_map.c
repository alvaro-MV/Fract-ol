/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:39:10 by alvmoral          #+#    #+#             */
/*   Updated: 2024/12/02 19:49:34 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	get_colour(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	get_color(int iterations, int max_iterations)
{
	double		t;
	uint32_t	color;

	t = (double)iterations / (double)max_iterations;
	if (t < 0.25)
		color = get_colour(255, 182, 193, 255);
	else if (t < 0.5)
		color = get_colour(255, 105, 180, 255);
	else if (t < 0.75)
		color = get_colour(0, 0, 128, 255);
	else if (t < 1.0)
		color = get_colour(0, 0, 0, 255);
	else
		color = get_colour(255, 255, 0, 255);
	return (color);
}
