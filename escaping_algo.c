#include "fractals.h"
#include "fract-ol.h"
#include "hooks.h"

void	print_pixel(t_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	* (unsigned int *) dst = color;
}

void	print_fractal(mlx_vars *vars, fractal *fract)
{
	int		i;
	int		j;
	int 	color;
	//char	**palette;

	i = 0;
	vars->img.img = mlx_new_image(vars->mlx, fract->win_height, fract->win_width);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, 
										&vars->img.line_length, &vars->img.endian);
	while (i < fract->win_height) 
	{
		j = 0;
		while (j < fract->win_width)
		{
			color = scape_mandelbrot(i, j, fract);
			color = (color + fract->color_offset) % 0x00ffffff;
			print_pixel(vars->img, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0,0);
}

void init_fractal( fractal *fract, char **argv)
{
	fract->x_axis = -2.0;
	fract->y_axis  =-1.5;
	fract->axis_range = 3.0;
	fract->color_offset = 0;
	fract->win_height = WIN_HEIGHT;
	fract->win_width = WIN_WIDTH;
	fract->max_iter = MAX_ITER;
	parse_params(argv, fract);
	//fract->fractal_func = get_fractal_funcs();
}

int	main(int argc, char **argv)
{
	mlx_vars	vars;
	fractal		fract;

	vars.mlx = mlx_init();
	argv++;
	init_fractal(&fract, argv);
	vars.fract = &fract;
	vars.height = fract.win_height;
	vars.width = fract.win_width;
	vars.win = mlx_new_window(vars.mlx, fract.win_height, fract.win_width, "Fractals");
	print_fractal(&vars, &fract);
	ft_printf("llega a 1");
	mlx_key_hook(vars.win, manage_keys, &vars);
	mlx_mouse_hook(vars.win, manage_mouse, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	return (0);
}
