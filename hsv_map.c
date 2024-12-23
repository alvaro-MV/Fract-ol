/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:31:59 by alvmoral          #+#    #+#             */
/*   Updated: 2024/12/02 19:49:12 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "colors.h"

void	hsv2rgb_calc_intermediate(t_hsv hsv_t)
{
	double	f;
	int		i;

	hsv_t.h /= 60;
	i = (int)hsv_t.h;
	f = hsv_t.h - i;
	*(hsv_t.p) = hsv_t.v * (1 - hsv_t.s);
	*(hsv_t.q) = hsv_t.v * (1 - hsv_t.s * f);
	*(hsv_t.t) = hsv_t.v * (1 - hsv_t.s * (1 - f));
}

void	hsv_fill_rgb(t_rgb *rgb_t, double hsv1, double hsv2, double hsv3)
{
	rgb_t->r = hsv1;
	rgb_t->g = hsv2;
	rgb_t->b = hsv3;
}

void	hsv2rgb_handle_saturation(t_rgb *rgb_t, t_hsv hsv_t)
{
	int	i;

	i = (int) hsv_t.h;
	if (i == 0)
		hsv_fill_rgb(rgb_t, hsv_t.v, *hsv_t.t, *hsv_t.p);
	else if (i == 1)
		hsv_fill_rgb(rgb_t, *hsv_t.q, hsv_t.v, *hsv_t.p);
	else if (i == 2)
		hsv_fill_rgb(rgb_t, *hsv_t.p, hsv_t.v, *hsv_t.t);
	else if (i == 3)
		hsv_fill_rgb(rgb_t, *hsv_t.p, *hsv_t.q, hsv_t.v);
	else if (i == 4)
		hsv_fill_rgb(rgb_t, *hsv_t.t, *hsv_t.p, hsv_t.v);
	else
		hsv_fill_rgb(rgb_t, hsv_t.v, *hsv_t.p, *hsv_t.q);
}

int	hsv2rgb_adjust_rgb(t_rgb rgb_t)
{
	int	r_l;
	int	g_l;
	int	b_l;

	r_l = (int)(rgb_t.r * 255);
	g_l = (int)(rgb_t.g * 255);
	b_l = (int)(rgb_t.b * 255);
	return (r_l << 16 | g_l << 8 | b_l);
}

int	hsv2rgb(double h, double s, double v)
{
	t_rgb		rgb_color;
	t_hsv		hsvpqt;

	if (s == 0)
	{
		rgb_color.r = v;
		rgb_color.g = v;
		rgb_color.b = v;
		return (0);
	}
	hsvpqt.h = h;
	hsvpqt.s = s;
	hsvpqt.v = v;
	hsvpqt.p = (double *) malloc(1 * sizeof(double));
	hsvpqt.q = (double *) malloc(1 * sizeof(double));
	hsvpqt.t = (double *) malloc(1 * sizeof(double));
	hsv2rgb_calc_intermediate(hsvpqt);
	hsv2rgb_handle_saturation(&rgb_color, hsvpqt);
	free(hsvpqt.p);
	free(hsvpqt.q);
	free(hsvpqt.t);
	return (hsv2rgb_adjust_rgb(rgb_color));
}
