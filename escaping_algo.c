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
	char	**palette;

	i = 0;
	palette = get_palette(COLOR_PATH, COLOR_MAP_LEN);
	vars->img.img = mlx_new_image(vars->mlx, fract->win_height, fract->win_width);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, 
										&vars->img.line_length, &vars->img.endian);
	printf("x axis: %lf,   y axis: %lf\n", fract->x_axis, fract->y_axis);
	while (i < fract->win_height) 
	{
		j = 0;
		while (j < fract->win_width)
		{
			color = scape_julia(i, j, fract);
			color += fract->color_offset * (1 - (color / fract->max_iter - 1));
			color = ft_xtoi(palette[color % COLOR_MAP_LEN]);
			print_pixel(vars->img, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0,0);
	ft_free_array(palette);
}

void init_fractal( fractal *fract)
{
	fract->x_axis = -2.0;
	fract->y_axis  =-1.5;
	fract->axis_range = 3.0;
	fract->color_offset = 0;
	fract->win_height = WIN_HEIGHT;
	fract->win_width = WIN_WIDTH;
	fract->max_iter = MAX_ITER;
	//fract->fractal_func = get_fractal_funcs();
}

int	main(void)
{
	mlx_vars	vars;
	char		*relative_path;
	fractal		fract;

	vars.mlx = mlx_init();
	init_fractal(&fract);
	vars.fract = &fract;
	vars.height = fract.win_height;
	vars.width = fract.win_width;
	vars.win = mlx_new_window(vars.mlx, fract.win_height, fract.win_width, "Mandelbrot");
	print_fractal(&vars, &fract);
	mlx_key_hook(vars.win, manage_keys, &vars);
	mlx_mouse_hook(vars.win, manage_mouse, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	return (0);
}
