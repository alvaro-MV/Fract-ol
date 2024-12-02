/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lyapunov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:36:52 by alvmoral          #+#    #+#             */
/*   Updated: 2024/12/02 20:01:38 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static double	absol(double n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

double	map_lambda_to_hue(double lambda, t_fractal *fract)
{
	long	*shifted_lambda;

	if (lambda <= 0)
	{
		lambda *= -1.0;
		shifted_lambda = (long *) &lambda;
		*shifted_lambda = *shifted_lambda >> 23;
		lambda = (double) *shifted_lambda;
		lambda /= (fract->max_iter * pow(10.0, 11.0));
		lambda = (lambda * 115.0) + 100.0;
		return (lambda);
	}
	else
		return (240.0);
}

double	calc_lambda(t_fractal *fract, double a, double b)
{
	double	r;
	double	x;
	double	lambda;
	int		n;

	x = 0.5;
	lambda = 0;
	n = 1;
	while (n < fract->max_iter)
	{
		if (n % 2 == 0)
			r = a;
		else
			r = b;
		x = r * x * (1 - x);
		lambda += log(absol(r * (1 - 2 * x)));
		n++;
	}
	fract->iter = n;
	return (lambda);
}

int	scape_lyapunov(int i, int j, void *vfract)
{
	double		a;
	double		b;
	double		lambda;
	double		hue;
	t_fractal	*fract;

	fract = (t_fractal *) vfract;
	a = fract->x_axis + i * (fract->axis / fract->win_h);
	b = fract->y_axis + j * (fract->axis / fract->win_h);
	lambda = calc_lambda(fract, a, b);
	hue = map_lambda_to_hue(lambda, fract);
	return (hsv2rgb(hue, 100.0, 100.0));
}
