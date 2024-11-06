#include "fractals.h"

int	calc_iter_mandel(fractal *fract, complex c)
{
	int		iter;
	complex	z;
	double	temp;

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
	complex	c;
	int		iter;
	double	hue;
	fractal	*fract;

	fract = (fractal *) vfract;
	c.re = fract->x_axis + i * (fract->axis_range / fract->win_height);
	c.im = fract->y_axis + j * (fract->axis_range / fract->win_width);
	iter = calc_iter_mandel(fract, c);
	hue = fmod(((double) iter * 360), fract->max_iter);
	hue = fmod(pow(hue, 1.5), 360);
	return (hsv2rgb(hue, 100.0, ((double)iter / fract->max_iter) * 100));
}

int	scape_julia(int i, int j, void *vfract)
{
	complex	z;
	int		iter;
	double	temp;
	double	hue;
	fractal	*fract;

	fract = (fractal *) vfract;
	z.re = fract->x_axis + i * (fract->axis_range / fract->win_height);
	z.im = fract->y_axis + j * (fract->axis_range / fract->win_width);
	iter = 0;
	while (iter < fract->max_iter && z.re * z.re + z.im * z.im < 4.0)
	{
		temp = z.re * z.re - z.im * z.im + fract->j_real;
		z.im = 2 * z.re * z.im + fract->j_im;
		z.re = temp;
		iter++;
	}
	hue = ((double) iter * 360) / fract->max_iter;
	hue = fmod(pow(hue, 1.5), 360);
	return (hsv2rgb(hue, 100.0, ((double)iter / fract->max_iter) * 100));
}

int	calc_iter_bship(fractal *fract, complex c)
{
	int		iter;
	complex	z;
	double	temp;

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
	complex	c;
	int		iter;
	double	hue;
	fractal	*fract;

	fract = (fractal *) vfract;
	c.re = fract->x_axis + i * (fract->axis_range / fract->win_height);
	c.im = fract->y_axis + j * (fract->axis_range / fract->win_width);
	iter = calc_iter_bship(fract, c);
	hue = ((double) iter * 360) / fract->max_iter;
	hue = fmod(pow(hue, 1.5), 360);
	return (hsv2rgb(hue, 100.0, ((double)iter / fract->max_iter) * 100));
}
