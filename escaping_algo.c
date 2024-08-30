
#include "fract-ol.h"

void	print_pixel(t_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	* (unsigned int *) dst = color;
}

int	get_scape(int i, int j, fractal *fract)
{
	double	re, im;
	int		iter;
	double	z_real, z_imag;
	double	temp;

	re = fract->x_axis + i * (fract->axis_range / fract->win_height);
	im = fract->y_axis + j * (fract->axis_range / fract->win_width);

	iter = 0;
	z_real = 0;
	z_imag = 0;
	//fract.fract_func();
	while (iter < MAX_ITER - 1 && z_real * z_real + z_imag * z_imag < 4.0) {
		temp = z_real * z_real - z_imag * z_imag + re;
		z_imag = 2 * z_real * z_imag + im;
		z_real = temp;
		iter++;
	}
	return (iter);
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
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
							&vars->img.endian);
    while (i < fract->win_height) 
	{
		j = 0;
		while (j < fract->win_width)
		{
			color = ft_xtoi(palette[get_scape(i, j, fract) % COLOR_MAP_LEN]);
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
	vars.height = fract.win_height;
	vars.width = fract.win_width;
	vars.win = mlx_new_window(vars.mlx, fract.win_height, fract.win_width, "Mandelbrot");
	print_fractal(&vars, &fract);
	mlx_key_hook(vars.mlx, manage_keys, &vars);

	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
}
