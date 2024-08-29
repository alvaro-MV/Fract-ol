#include "mlx.h"
#include "mlx_int.h"
#include <unistd.h>
#include <stdio.h>
#include "lib/include/libft.h"
#include "fract-ol.h"
#include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef	struct var_mlx {
	void	*win;
	void	*mlx;
	t_data	img;
	int		height;
	int		width;
	int		height_offset;
}			mlx_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_circle(int centrus_x, int centrus_y, int radius, t_data img)
{
	int i = centrus_x - radius;
	int j = centrus_y - radius;
	int	radius2 = radius*radius;
	int color = 0x00ff;
	ft_printf("color: %d\n", color);
	while (i < centrus_x + radius)
	{
		j = centrus_y - radius;
		while (j < centrus_y + radius)
		{
			if ((i - centrus_x)*(i - centrus_x) + (j - centrus_y)*(j - centrus_y) < radius2 - radius2/3
				&& (i - centrus_x)*(i - centrus_x) + (j - centrus_y)*(j - centrus_y) < radius2 + radius2/3)
					my_mlx_pixel_put(&img, i, j, color);
			j++;
		}
		i++;
	}
}

int	get_scape(int i, int j)
{
	double	re, im;
	int iteration = 0;
	double	z_n_re, z_n_im;

	re = 2 * ((double)(450 - i) / 450);
	im = 2 * ((double)(450 - j) / 450);
	z_n_re = 0;
	z_n_im = 0;

	while (iteration < 20)
	{
		if (z_n_re*z_n_re + z_n_im*z_n_im > 4)
			return (0x00ffffff);
		z_n_re = pow(z_n_re, 2) - pow(z_n_im, 2) + re;
		z_n_im = (2 * z_n_re * z_n_im) + im;
		iteration = iteration + 1;
	}
	return (0x0);
}

int	print_rainbow(mlx_vars *vars, int sizze)
{
	int	j;
	int	i;

	vars->img.img = mlx_new_image(vars->mlx, sizze, sizze);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
							&vars->img.endian);
	j = 0;
	while (j < sizze)
	{
		i = 0;
		while (i < sizze)
		{
			my_mlx_pixel_put(&vars->img, j, i, get_scape(i, j));
			i++;
		}
		vars->height_offset++;
		j++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	move_circle(int keymap, mlx_vars *vars)
{
	static int	centrus_x = 70;
	static int centrus_y = 70;;
	int radius = 60;

	ft_printf("keymap: %d\n", keymap);
	if (keymap == 65364)
		centrus_y += radius + 10;
	if (keymap == 65363)
		centrus_x += radius + 10;
	if (keymap == 65361)
		centrus_x -= radius - 10;
	if (keymap == 65362)
		centrus_y -= radius - 10;
	free(vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, 500, 400);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
							&vars->img.endian);
	print_circle(centrus_x, centrus_y, radius, vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	mlx_vars	vars;
	t_data		img;
	int			sizze = 5000;	

	vars.mlx = mlx_init();
	vars.height = sizze;
	vars.width = sizze;
	vars.height_offset = 0;
	vars.win = mlx_new_window(vars.mlx, sizze, sizze, "Hello world!");
	img.img = mlx_new_image(vars.mlx, sizze, sizze);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	vars.img = img;
	print_rainbow(&vars, sizze);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
}

