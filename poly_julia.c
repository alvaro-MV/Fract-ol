#include "fractals.h"

int	get_poly_iter(double z_real, double z_imag, fractal *fract)
{
	int		iter;
	double	temp;
	double	re, im; //Esto se ha de controlar por CLI

	iter = 0;
	re = 0.04;
	im = 0.0;
	while (iter < fract->max_iter && z_real * z_real + z_imag * z_imag < 4.0)
	{
		temp = z_real * z_real - z_imag * z_imag + re;
		z_real =  2 * z_real * z_imag + im;
		z_imag = temp;
		temp = (z_real + z_imag) * cos(z_real);
		z_imag = (z_real + z_imag) * sin(z_real);
		iter++;
	}
	return (iter);
}

int	scape_julia_poly(int i, int j, fractal *fract)
{
	double	z_real, z_imag;
	double	hue;
	int		iter;

	z_real = fract->x_axis + i * (fract->axis_range / fract->win_height); //Assuming R = 2;
	z_imag = fract->y_axis + j * (fract->axis_range / fract->win_width);
	iter = get_poly_iter(z_real, z_imag, fract);
	hue = ((double) iter * 360) / fract->max_iter;
	hue = fmod(pow(hue, 1.5), 360);	
	return (hsv2rgb(hue, 100.0, ((double) iter / fract->max_iter) * 100));
}
