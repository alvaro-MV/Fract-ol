#include "fractals.h"

static double	absol(double n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}
int	scape_lyapunov(int i, int j, void *vfract)
{
	double	A;
	double	B;
	double	x;
	double	r;
	double	lambda;
	double	hue;
	int		n;
	fractal	*fract;

	fract = (fractal *) vfract;
	A = 0 + i * (4.0 / 900);
	B = 0 + j * (4.0 / 900);
	x = 0.5;
	n = 1;
	lambda = 0;
	while (n < fract->max_iter)
	{
		if (n % 2 == 0) 
			r = A;
		else
			r = B;
		x = r * x * (1 - x);
		lambda += log(absol(r * (1 - 2 * x)));
		n++;
	}
	lambda = ((lambda * 180) / fract->max_iter) + 180;
	hue = fmod(pow(lambda, 1.5), 360);
	return (hsv2rgb(hue, 100.0, lambda));
}
