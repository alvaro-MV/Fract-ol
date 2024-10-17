#include "fractals.h"

static double	absol(double n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

double map_lambda_to_hue(double lambda, fractal *fract)
{
	double	max;
	long	*shifted_lambda;
	max = fract->max_iter * 10.0;
    if (lambda <= 0)
	{
		lambda *= -1.0;
		shifted_lambda = (long *) &lambda;
		*shifted_lambda = *shifted_lambda >> 23;
		lambda = (double) *shifted_lambda;
		lambda /= (fract->max_iter * 100000000000.0);
		lambda = (lambda *115.0) + 100.0;
		return (lambda);
    }
	else
	{
        // Map positive lambdas to blue
        return (240);
    }
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
	hue = map_lambda_to_hue(lambda, fract);
	return (hsv2rgb(hue, 100.0, 100.0));
}
