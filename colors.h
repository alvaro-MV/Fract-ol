/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:37:46 by alvmoral          #+#    #+#             */
/*   Updated: 2024/12/02 19:41:19 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <ctype.h>

typedef struct s_hsv
{
	double	h;
	double	s;
	double	v;	
	double	*p;
	double	*q;
	double	*t;
}			t_hsv;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}			t_rgb;

void		hsv2rgb_calc_intermediate(t_hsv hsv_t);
void		hsv_fill_rgb(t_rgb *rgb_t, double hsv1, double hsv2, double hsv3);
void		hsv2rgb_handle_saturation(t_rgb *rgb_t, t_hsv hsv_t);
int			hsv2rgb_adjust_rgb(t_rgb rgb_t);
int			hsv2rgb(double h, double s, double v);
int32_t		get_colour(int32_t r, int32_t g, int32_t b, int32_t a);
uint32_t	get_color(int iterations, int max_iterations);

#endif