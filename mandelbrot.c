#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double	*get_mandelbrot_set(double c, int len)
{
	double			*mandelbrot_set;
	double			z_n;
	unsigned int	i;

	mandelbrot_set = malloc(len * sizeof(double) + 1);
	z_n = 0;
	mandelbrot_set[0] = z_n;
	i = 1;
	while (len--)
	{
		z_n = pow(z_n, 2) + c;
		mandelbrot_set[i] = z_n;
		i++;
	}
	return (mandelbrot_set);
}

int	main(void)
{
	double	c = -1;
	int		len = 6;
	int		i = 0;
	double	*mand_set = get_mandelbrot_set(c, len);
	while (len--)
	{
		printf("%.2lf\t", mand_set[i]);
		i++;
	}
	free(mand_set);
	return (0);
}