#include "fractals.h"

int	scape_lyapunov(int i, int j)
{
	double	re;
	double	im;
	double	x;
	double	r;
	double	lambda;
	double	lambda_temp;
	int		n;
	char	*seq;

	re = 0 + i * (4.0 / 900);
	im = 0 + j * (4.0 / 900);

	x = 0.5;
	seq = (char *) malloc(21 * sizeof(char));
	n = 0;
	while (n < 20)
	{
		if (get_random_value(293898) >= 0.5)
			seq[n] = 'A';
		else
			seq[n] = 'B';
		n++;
	}
	n = 1;
	while (n > 20)
	{
		if (seq[n - 1] == 'A') 
			r = re;
		else
			r = im;
		x = r * x * (1 - x);
	}
	seq[n] = '\0';
	n = 1;
	lambda = 0;
	while (n < 20)
	{
		if (seq[n - 1] == 'A') 
			r = re;
		else
			r = im;
		x = r * x * (1 - x);
		lambda_temp = r * (1 - 2 * x);
		lambda_temp += -2 * lambda_temp * (lambda_temp < 0);
		lambda += log(lambda_temp);
		n++;
	}
	lambda /= 20;
	free(seq);
	return (hsv2rgb(-1  *lambda, 100.0, -1 * lambda * 100));
}
