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

int	get_next_mand_n(complex c, complex *z_n, int *iteration) 
{
	if (*iteration >= MAX_ITER - 1)
		return (0);
	if (*iteration == 0)
	{
		z_n->re = 0;
		z_n->im = 0;
	}
	z_n->re = pow(z_n->re, 2) - pow(z_n->im, 2) + c.re;
	z_n->im = (2 * z_n->re * z_n->im) + c.im;
	*iteration = *iteration + 1;
	return (1);
}

void	print_complex(complex mand_num)
{
	printf("%.6lf", mand_num.re);
	if (mand_num.im != 0)
	{
		if (mand_num.im < 0)
			printf(" - ");
		else
			printf(" + ");
		printf("%.6lfi", mand_num.im);
	}
	printf("\n");
}

int	get_iteration(complex c)
{
	complex	z_n;
	int		counter = 0;
	int		iteration;

	print_complex(c);
	iteration = 0;
	while (get_next_mand_n(c, &z_n, &iteration))
	{
		if (z_n.re*z_n.re + z_n.im*z_n.im > 4.0)
			break ;
		counter++;
	}
	//printf("counter. %d\n", counter);
	return (counter);
}

//int	main(void)
//{
	//char **palette = get_palette(COLOR_PATH, COLOR_MAP_LEN);
	//complex c;
	//fractal	fract = {0, 0, 2, -2};
	//int i = 0;
	//int	j = 0;
	//int color;
	//get_size_increment(&fract);
	//c.re = 0.345;
	//c.im = 0.7823;
	//printf("high  : %lf, width: %lf\n", fract.heigth_incr, fract.width_incr);
	//int counter = get_iteration(c, MAX_ITER);
	//ft_printf("color: %s\n", palette[counter]);
	//c.im += fract.heigth_incr;
	//printf("c imaginario:%lf\n\n", c.im);
	//counter = get_iteration(c, MAX_ITER);
	//ft_printf("color: %s\n", palette[counter]);
//}