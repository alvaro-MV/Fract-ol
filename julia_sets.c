#include "fractals.h"

int	get_poly_iter_3(double z_real, double z_imag, fractal *fract)
{
	int		iter;
	double	temp;

	iter = 0;
	while (iter < fract->max_iter && z_real * z_real + z_imag * z_imag < 4.0)
	{
		temp = pow(z_real, 3) - 3.0 * z_real * pow(z_imag, 2) + fract->j_real;
		z_imag = (3 * pow(z_real, 2) * z_imag) - pow(z_imag, 3) + fract->j_im;
		z_real = temp;
		iter++;
	}
	return (iter);
}

int	get_exp_iter(double z_real, double z_imag, fractal *fract)
{
	int		iter;
	double	temp;

	iter = 0;
	while (iter < fract->max_iter && z_real * z_real + z_imag * z_imag < 4.0)
	{
		temp = exp(z_real) * cos(z_imag) + fract->j_real;
		z_imag = exp(z_real) * sin(z_imag) + fract->j_real;
		z_real = temp;
		iter++;
	}
	return (iter);
}

int	scape_julia_sets(int i, int j, fractal *fract)
{
	double	z_real, z_imag;
	double	hue;
	int		iter;

	z_real = fract->x_axis + i * (fract->axis / fract->win_h);
	z_imag = fract->y_axis + j * (fract->axis / fract->win_w);
	iter = get_poly_iter_3(z_real, z_imag, fract);
	hue = ((double) iter * 360) / fract->max_iter;
	hue = fmod(pow(hue, 1.5), 360);	
	return (hsv2rgb(hue, 100.0, ((double) iter / fract->max_iter) * 100));
}
