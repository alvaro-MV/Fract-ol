/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:39:10 by alvmoral          #+#    #+#             */
/*   Updated: 2024/11/13 14:39:11 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

uint32_t get_colour(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

uint32_t get_color_rgb(int iterations, int max_iterations)
{
    double t = (double)iterations / (double)max_iterations;
    int r, g, b;
    
    if (t < 0.25) {
        // Tonos de rosa claro
        r = 255;
        g = (int)(255 * (1 - 4 * t));
        b = (int)(255 * (1 - 4 * t));
    } else if (t < 0.5) {
        // Tonos de rosa oscuro
        r = 255;
        g = (int)(128 * (2 - 4 * t));
        b = (int)(128 * (2 - 4 * t));
    } else if (t < 0.75) {
        // Azul marino
        r = (int)(128 * (3 - 4 * t));
        g = (int)(128 * (3 - 4 * t));
        b = 255;
    } else if (t < 1.0) {
        // Negro
        r = (int)(255 * (4 - 4 * t));
        g = (int)(255 * (4 - 4 * t));
        b = (int)(255 * (4 - 4 * t));
    } else {
        // Amarillo (en caso de necesitar un color extra)
        r = 255;
        g = 255;
        b = 0;
    }
    return get_colour(r, g, b, 255);
}