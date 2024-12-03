/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:36:41 by alvmoral          #+#    #+#             */
/*   Updated: 2024/12/03 10:31:12 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "fractol.h"
#include "hooks.h"

void	print_pixel(t_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	print_fractal(t_mlx_vars *vars, t_fractal *fract)
{
	int		i;
	int		j;
	int		color;
	t_data	im;

	i = 0;
	im = vars->img;
	im.img = mlx_new_image(vars->mlx, fract->win_h, fract->win_w);
	im.addr = mlx_get_data_addr(im.img, &im.bits_per_pixel,
			&im.line_length, &im.endian);
	vars->img = im;
	while (i < fract->win_h)
	{
		j = 0;
		while (j < fract->win_w)
		{
			color = fract->fractal_func(i, j, fract);
			color = (color + fract->color_offset) % 0x00ffffff;
			color += 5 * 0x00111112;
			print_pixel(vars->img, i, j++, (color * fract->iter));
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	close_win(t_mlx_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	init_fractal(t_mlx_vars *vars, char **argv)
{
	t_fractal	*fract;

	fract = vars->fract;
	fract->x_axis = -2.0;
	fract->y_axis = -1.5;
	fract->axis = 3.0;
	fract->color_offset = 0;
	fract->win_h = WIN_HEIGHT;
	fract->win_w = WIN_WIDTH;
	fract->max_iter = MAX_ITER;
	if (!parse_params(argv, fract))
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(-1);
	}
}

int	main(int argc, char **argv)
{
	t_mlx_vars		vars;
	t_fractal		fract;

	(void) argc;
	vars.mlx = mlx_init();
	argv++;
	vars.fract = &fract;
	init_fractal(&vars, argv);
	vars.height = fract.win_h;
	vars.width = fract.win_w;
	vars.win = mlx_new_window(vars.mlx, fract.win_h, fract.win_w, "");
	print_fractal(&vars, &fract);
	mlx_key_hook(vars.win, manage_keys, &vars);
	mlx_mouse_hook(vars.win, manage_mouse, &vars);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, close_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
