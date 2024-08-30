
#include "fract-ol.h"



void	print_pixel(t_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	* (unsigned int *) dst = color;
}

int	get_scape(int i, int j, int sizze)
{
	double	re, im;
	int		iter;
	double	z_real, z_imag;
	double	temp;

	re = -1.0 + j * (3 / 900.0);
	im = -1.5 + i * (3 / 900.0);

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

void	print_mandel(mlx_vars *vars, int sizze)
{
	int		i;
	int		j;
	char	**palette;

	i = 0;
	palette = get_palette(COLOR_PATH, COLOR_MAP_LEN);
	vars->img.img = mlx_new_image(vars->mlx, sizze, sizze);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
							&vars->img.endian);
    while (i < sizze) 
	{
		j = 0;
		while (j < sizze)
		{
			print_pixel(vars->img, i, j, ft_xtoi(palette[get_scape(i, j, sizze) % COLOR_MAP_LEN]));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0,0);
	ft_free_array(palette);
}

void init_fractal( fractal *fract)
{
	fract->heigth_incr = 3.0 / WIN_HEIGHT;
	fract->width_incr = 3.0 / WIN_WIDTH;
	fract->x_axis = -2.0;
	fract->y_axis  =-1.5;
}

int	main(void)
{
	mlx_vars	vars;
	t_data		img;
	char		*relative_path;
	complex		c;

	vars.mlx = mlx_init();
	vars.height = WIN_HEIGHT;
	vars.width = WIN_WIDTH;
	vars.win = mlx_new_window(vars.mlx, WIN_HEIGHT, WIN_WIDTH, "Mandelbrot");
	print_mandel(&vars, WIN_HEIGHT);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
}
