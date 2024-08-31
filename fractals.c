#include "fractals.h"

int	scape_mandelbrot(int i, int j, fractal *fract)
{
	double	re, im;
	int		iter;
	double	z_real, z_imag;
	double	temp;

	re = fract->x_axis + i * (fract->axis_range / fract->win_height);
	im = fract->y_axis + j * (fract->axis_range / fract->win_width);

	iter = 0;
	z_real = 0;
	z_imag = 0;
	while (iter < fract->max_iter && z_real * z_real + z_imag * z_imag < 4.0) {
		temp = z_real * z_real - z_imag * z_imag + re;
		z_imag = 2 * z_real * z_imag + im;
		z_real = temp;
		iter++;
	}
	return (iter);
}
