#include "fractals.h"

int	scape_lyapunov(int i, int j)
{
	double	z_real;
	double	z_imag;
	double	lyapunov;
	double	hue;
	int		iter;
	double	r;
	double	theta;

	z_real = 0 + i * (4.0 / 900);
	z_imag = 0 + j * (4.0 / 900);
	iter = 0;
	r = 0;
	theta = 0;
	lyapunov = 0;
	while (iter < MAX_ITER && (z_real * z_real + z_imag * z_imag) <= 4)
	{
		r = 0.01 + sqrt(z_real * z_real + z_imag * z_imag);
		printf("r desp: %lf\n", r);
		theta = atan2(z_imag, z_real);
		z_real = r * cos(theta);
		printf("z_rela: %lf\n", z_real);
		z_imag = r * sin(theta);
		lyapunov += log(r);
		iter++;
	}
	lyapunov = (255.0 - (lyapunov / MAX_ITER) * 255.0);
	hue = ((double) iter * 360) / MAX_ITER;
	hue = fmod(pow(hue, 1.5), 360);	
	printf("soy lyapu: %lf\n", hue);
	return (hsv2rgb(hue, 100.0, -1 * lyapunov * 100));
}
