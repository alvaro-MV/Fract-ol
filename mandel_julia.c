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
	hue = ((double) iter * 360) / fract->max_iter;
	hue = fmod(pow(hue, 1.5), 360);	
	return (hsv2rgb(hue, 100.0, ((double)iter / fract->max_iter) * 100));
}

int	scape_julia(int i, int j, fractal *fract)
{
	double	re, im; //Esto se ha de controlar por CLI
	double	z_real, z_imag;
	int		iter;
	double	temp;
	double	hue;

	z_real = fract->x_axis + i * (fract->axis_range / fract->win_height); //Assuming R = 2;
	z_imag = fract->y_axis + j * (fract->axis_range / fract->win_width);

	iter = 0;
	re = -0.8;
	im = 0.156;
	while (iter < fract->max_iter && z_real * z_real + z_imag * z_imag < 4.0)
	{
		temp = z_real * z_real - z_imag * z_imag + re;
		z_imag = 2 * z_real * z_imag + im;
		z_real = temp;
		iter++;
	}
	hue = ((double) iter * 360) / fract->max_iter;
	hue = fmod(pow(hue, 1.5), 360);	
	return (hsv2rgb(hue, 100.0, ((double)iter / fract->max_iter) * 100));
}

int	scape_burning_ship(int i, int j, fractal *fract)
{
	complex	c;
	int		iter;
	complex	z;
	double	temp;
	double	hue;

	c.re = fract->x_axis + i * (fract->axis_range / fract->win_height);
	c.im = fract->y_axis + j * (fract->axis_range / fract->win_width);

	iter = 0;
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
	hue = ((double) iter * 360) / fract->max_iter;
	hue = fmod(pow(hue, 1.5), 360);	
	return (hsv2rgb(hue, 100.0, ((double)iter / fract->max_iter) * 100));
}
