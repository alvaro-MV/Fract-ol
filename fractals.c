#include "fractals.h"

int	scape_mandelbrot(int i, int j, fractal *fract)
{
	complex	c;
	int		iter;
	complex	z;
	double	temp;
	double	hue;

	c.re = fract->x_axis + i * (fract->axis_range / fract->win_height);
	c.im = fract->y_axis + j * (fract->axis_range / fract->win_width);

	iter = 0;
	z.re = 0;
	z.im = 0;
	while (iter < fract->max_iter && z.re * z.re + z.im * z.im < (1 << 16))
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		iter++;
	}
	hue = iter / fract->max_iter * 360;	
	return (hsv2rgb(hue, 1.0, 1.0));
}

int	scape_julia(int i, int j, fractal *fract)
{
	double	re, im; //Esto se ha de controlar por CLI
	double	z_real, z_imag;
	int		iter;
	double	temp;

	z_real = fract->x_axis + i * (fract->axis_range / fract->win_height); //Assuming R = 2;
	z_imag = fract->y_axis + j * (fract->axis_range / fract->win_width);

	iter = 0;
	re = 0.285;
	im = -0.01;
	while (iter < fract->max_iter && z_real * z_real + z_imag * z_imag < 4.0)
	{
		temp = z_real * z_real - z_imag * z_imag + re;
		z_imag = 2 * z_real * z_imag + im;
		z_real = temp;
		iter++;
	}
	return (iter);
}

int	scape_julia_cosh(int i, int j, fractal *fract)
{
	double	re, im; //Esto se ha de controlar por CLI
	double	z_real, z_imag;
	int		iter;
	double	temp;

	z_real = fract->x_axis + i * (fract->axis_range / fract->win_height); //Assuming R = 2;
	z_imag = fract->y_axis + j * (fract->axis_range / fract->win_width);

	iter = 0;
	re = 0.285;
	im = -0.01;
	while (iter < fract->max_iter && z_real * z_real + z_imag * z_imag < 4.0)
	{
		temp = z_real * z_real - z_imag * z_imag + re;
		z_imag = 2 * z_real * z_imag + im;
		z_real = temp;
		iter++;
	}
	return (iter);
}
