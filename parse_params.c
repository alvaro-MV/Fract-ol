#include "fract-ol.h"

static int	check_floats_julia(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argv[3] != NULL)
		return (0);
	while (i < 3)
	{
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9')
				&& argv[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_help_message(void)
{
	ft_printf("usage: fract-ol -m | -j [<real const part>]");
	ft_printf(" [<imaginary const part>]\n");
	ft_printf("\t-m: print the mandelbrot set.\n");
	ft_printf("\t-j: print the julia set.\n");
	ft_printf("\t\t<real const part>: the real part ");
	ft_printf("of c in the f(z) = z^2 + c expression.\n");
	ft_printf("\t\t<imaginary const part>: the imaginary part ");
	ft_printf("of c in the f(z) = z^2 + c expression.\n");
}

int	parse_params(char **argv, fractal *fract)
{
	if (ft_strcmp(*argv, "-m") == 1 || ft_strcmp(*argv, "-j") == 1)
	{
		print_help_message();
		return (0);
	}
	else if (ft_strcmp(*argv, "-m") == 0 && argv[1] != NULL)
	{
		print_help_message();
		return (0);
	}
	else if (ft_strcmp(*argv, "-j") == 0)
	{
		if (!check_floats_julia(argv))
		{
			print_help_message();
			return (0);
		}
		fract->j_real = ft_atof(argv[1]);
		fract->j_im = ft_atof(argv[2]);
	}
	else if (ft_strcmp(*argv, "-l") == 0)
		ft_printf("lypunoooooooooov\n");
	return (1);
}
