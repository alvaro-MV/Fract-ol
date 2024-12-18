/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:38:32 by alvmoral          #+#    #+#             */
/*   Updated: 2024/12/18 11:23:33 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "colors.h"

int	calc_iter_mandel(t_fractal *fract, t_complex c)
{
	int			iter;
	t_complex	z;
	double		temp;

	iter = 0;
	z.re = 0;
	z.im = 0;
	temp = 0;
	while (iter < fract->max_iter && z.re * z.re + z.im * z.im < 4)
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		iter++;
	}
	return (iter);
}

int	scape_mandelbrot(int i, int j, void *vfract)
{
	t_complex	c;
	int			iter;
	t_fractal	*fract;
	double		hue;

	fract = (t_fractal *) vfract;
	c.re = fract->x_axis + i * (fract->axis / fract->win_h);
	c.im = fract->y_axis + j * (fract->axis / fract->win_w);
	iter = calc_iter_mandel(fract, c);
	fract->iter = iter;
	hue = ((double) iter * 360) / fract->max_iter;
	hue = fmod(pow(hue, 1.5), 360);
	return (hsv2rgb(hue, 100.0, ((double)iter / fract->max_iter) * 100));
}

int	scape_julia(int i, int j, void *vfract)
{
	t_complex	z;
	int			iter;
	double		temp;
	double		hue;
	t_fractal	*fract;

	fract = (t_fractal *) vfract;
	z.re = fract->x_axis + i * (fract->axis / fract->win_h);
	z.im = fract->y_axis + j * (fract->axis / fract->win_w);
	iter = 0;
	while (iter < fract->max_iter && z.re * z.re + z.im * z.im < 4.0)
	{
		temp = z.re * z.re - z.im * z.im + fract->j_real;
		z.im = 2 * z.re * z.im + fract->j_im;
		z.re = temp;
		iter++;
	}
	fract->iter = iter;
	hue = ((double) iter * 360) / fract->max_iter;
	hue = fmod(pow(hue, 1.5), 360);
	return (hsv2rgb(hue, 100.0, ((double)iter / fract->max_iter) * 100));
}

int	calc_iter_bship(t_fractal *fract, t_complex c)
{
	int			iter;
	t_complex	z;
	double		temp;

	iter = 0;
	temp = 0;
	z.re = c.re;
	z.im = c.im;
	while (iter < fract->max_iter && z.re * z.re + z.im * z.im < (1 << 16))
	{
		z.re += (z.re < 0) * -2 * z.re;
		z.im += (z.im < 0) * -2 * z.im;
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		iter++;
	}
	return (iter);
}

int	scape_burning_ship(int i, int j, void *vfract)
{
	t_complex	c;
	int			iter;
	t_fractal	*fract;

	fract = (t_fractal *) vfract;
	c.re = fract->x_axis + i * (fract->axis / fract->win_h);
	c.im = fract->y_axis + j * (fract->axis / fract->win_w);
	iter = calc_iter_bship(fract, c);
	fract->iter = iter;
	return (get_color(iter, fract->max_iter));
}
