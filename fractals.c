#include "fractals.h"

int	scape_mandelbrot(int i, int j, fractal *fract)
{
	double	re, im;
	int		iter;
	double	z_real, z_imag;
	double	temp;
	double	v_nu;

	re = fract->x_axis + i * (fract->axis_range / fract->win_height);
	im = fract->y_axis + j * (fract->axis_range / fract->win_width);

	iter = 0;
	z_real = 0;
	z_imag = 0;
	v_nu = 0;
	while (iter < fract->max_iter && z_real * z_real + z_imag * z_imag < (1 << 16))
	{
		temp = z_real * z_real - z_imag * z_imag + re;
		z_imag = 2 * z_real * z_imag + im;
		z_real = temp;
		iter++;
	}
	if (iter < fract->max_iter)
		v_nu += 1 - log((log(z_real * z_real + z_imag * z_imag) / 2) / log(2)) / log(2);
	return (iter + v_nu);
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

int	scape_julia_exp_2(int i, int j, fractal *fract)
{
	double	re, im; //Esto se ha de controlar por CLI
	double	z_real, z_imag;
	int		iter;
	double	temp;

	z_real = fract->x_axis + i * (fract->axis_range / fract->win_height); //Assuming R = 2;
	z_imag = fract->y_axis + j * (fract->axis_range / fract->win_width);

	iter = 0;
	re = 0.21;
	im = 0;
	while (iter < fract->max_iter && z_real * z_real + z_imag * z_imag < 4.0)
	{
		temp = (z_real * z_real - z_imag * z_imag)*exp(z_real)*exp(z_imag) + re;
		z_imag = (2 * z_real * z_imag)*exp(z_real)*exp(z_imag) + im;
		z_real = temp;
		iter++;
	}
	return (iter);
}