#include "fractals.h"

static double	absol(double n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

double	map_lambda_to_hue(double lambda, fractal *fract)
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

double	calc_lambda(fractal *fract, double a, double b)
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
	return (lambda);
}

int	scape_lyapunov(int i, int j, void *vfract)
{
	double	a;
	double	b;
	double	lambda;
	double	hue;
	fractal	*fract;

	fract = (fractal *) vfract;
	a = fract->x_axis + i * (fract->axis_range / fract->win_height);
	b = fract->y_axis + j * (fract->axis_range / fract->win_height);
	lambda = calc_lambda(fract, a, b);
	hue = map_lambda_to_hue(lambda, fract);
	return (hsv2rgb(hue, 100.0, 100.0));
}
