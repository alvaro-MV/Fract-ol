#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fract-ol.h"
#include "lib/include/libft.h"

complex	*get_mandelbrot_set(complex c, int len)
{
	complex			*mandelbrot_set;
	complex			z_n;
	unsigned int	i;

	mandelbrot_set = malloc((len + 1) * sizeof(complex));
	z_n.re = 0;
	z_n.im = 0;
	mandelbrot_set[0] = z_n;
	i = 1;
	while (len--)
	{
		z_n.re = pow(z_n.re, 2) - pow(z_n.im, 2) + c.re;
		z_n.im = (2 * z_n.re * z_n.im) + c.im;
		mandelbrot_set[i] = z_n;
		i++;
	}
	return (mandelbrot_set);
}

int	get_next_mand_n(complex c, complex *z_n, int max_iteration) 
{
	static int	iteration;

	if (iteration >= max_iteration)
		return (0);
	if (iteration == 0)
	{
		z_n->re = 0;
		z_n->im = 0;
	}
	z_n->re = pow(z_n->re, 2) - pow(z_n->im, 2) + c.re;
	z_n->im = (2 * z_n->re * z_n->im) + c.im;
	iteration++;
	return (1);
}

void	print_complex(complex mand_num)
{
	printf("%.1lf", mand_num.re);
	if (mand_num.im != 0)
	{
		if (mand_num.im < 0)
			printf(" - ");
		else
			printf(" + ");
		printf("%.1lfi", mand_num.im);
	}
	printf("\n");
}

int	get_iteration(complex c, int max_iter)
{
	complex	z_n;
	int		counter = 0;

	c.re = 1;
	c.im = 0;
	while (get_next_mand_n(c, &z_n, max_iter))
	{
		if (z_n.re*z_n.re + z_n.im*z_n.im > 4)
			break ;
		counter++;
	}
	return (counter);
}