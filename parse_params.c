/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:38:45 by alvmoral          #+#    #+#             */
/*   Updated: 2024/12/03 10:56:53 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractals.h"

static int	check_floats_julia(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argv[3] != NULL)
		return (0);
	while (i < 3)
	{
		j = 0;
		if (argv[i][0] == '+' || argv[i][0] == '-')
			j++;
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
	ft_putstr_fd("usage: fract-ol -m | -j [<real const part>] | -b | -l", 2);
	ft_putstr_fd(" [<imaginary const part>]\n", 2);
	ft_putstr_fd("\t-m: print the mandelbrot set.\n", 2);
	ft_putstr_fd("\t-j: print the julia set.\n", 2);
	ft_putstr_fd("\t\t<real const part>: the real part ", 2);
	ft_putstr_fd("of c in the f(z) = z^2 + c expression.\n", 2);
	ft_putstr_fd("\t\t<imaginary const part>: the imaginary part ", 2);
	ft_putstr_fd("of c in the f(z) = z^2 + c expression.\n", 2);
	ft_putstr_fd("\t-b: print the burning ship fractal.\n", 2);
	ft_putstr_fd("\t-l: print the lyapunov fractal.\n", 2);
}

int	print_error_msg(void)
{
	print_help_message();
	return (0);
}

void	init_lyapunov(t_fractal *fract)
{
	fract->fractal_func = scape_lyapunov;
	fract->axis = 4.0;
	fract->x_axis = 0.0;
	fract->y_axis = 0.0;
	fract->max_iter = 500;
}

int	parse_params(char **argv, t_fractal *fract)
{
	if (ft_strcmp(*argv, "-m") == 1 || ft_strcmp(*argv, "-j") == 1)
		return (print_error_msg());
	else if (ft_strcmp(*argv, "-m") == 0 && argv[1] != NULL)
		return (print_error_msg());
	else if (ft_strcmp(*argv, "-m") == 0)
		fract->fractal_func = scape_mandelbrot;
	else if (ft_strcmp(*argv, "-j") == 0)
	{
		if (!check_floats_julia(argv))
			return (print_error_msg());
		fract->j_real = ft_atof(argv[1]);
		fract->j_im = ft_atof(argv[2]);
		fract->fractal_func = scape_julia;
	}
	else if (ft_strcmp(*argv, "-l") == 0)
		init_lyapunov(fract);
	else if (ft_strcmp(*argv, "-b") == 0)
		fract->fractal_func = scape_burning_ship;
	else
		return (print_error_msg());
	return (1);
}
