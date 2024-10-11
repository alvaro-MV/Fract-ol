#include "fractals.h"

static double	absol(double n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

double map_lambda_to_hue(double lambda)
{
    if (lambda <= 0)
	{
        // Map negative and zero lambdas to yellow
        return (60);
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
	hue = map_lambda_to_hue(lambda);
	return (hsv2rgb(fmod(hue,  360.0), fmod(fabs(lambda), 0.1), fmod(lambda, 100.0)));
}
