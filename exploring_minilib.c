#include "mlx.h"
#include "mlx_int.h"
#include <unistd.h>
#include <stdio.h>
#include "lib/include/libft.h"
#include "colors.h"
#include <math.h>

///usr/bin/ld: cannot find -llibmlx_Linux: No such file or directory
///usr/bin/ld: note to link with mlx_linux/libmlx_Linux.a use -l:libmlx_Linux.a or rename it to liblibmlx_Linux.a

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

# define COLOR_PATH "colors.txt"
# define COLOR_MAP_LEN 754

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
	char	**color_values = get_palette("colors.txt", COLOR_MAP_LEN);
	int color = ft_atoi(color_values[((centrus_x + centrus_y) / 2) % COLOR_MAP_LEN]);
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

int	print_rainbow(int keymap, mlx_vars *vars)
{
	int	j;
	int	flag_height = 5;
	int	i;
	int col_ra = 0;
	int rainbow[] = {0xff0000, 0xffff00, 0x00ff00, 0x00ffff, 0x0000ff, 0xff00ff, 0xff0000};

	if (keymap == 65364)
	{
		vars->img.img = mlx_new_image(vars->mlx, 900, 800);
		vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
								&vars->img.endian);
		while (col_ra < 7)
		{
			j = 0;
			while (j < flag_height)
			{
				i = 0;
				while (i < vars->width)
				{
					my_mlx_pixel_put(&vars->img, i, vars->height_offset, rainbow[col_ra]);
					i++;
				}
				vars->height_offset++;
				j++;
			}
			col_ra++;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	return (0);
}

int	move_circle(int keymap, mlx_vars *vars)
{
	static int	centrus_x = 70;
	static int centrus_y = 70;;
	int radius = 60;
	int	color = 0x00ff00;

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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 200, 200);
	return (0);
}

int	main(void)
{
	mlx_vars	vars;
	t_data		img;
	char		*relative_path;

	vars.mlx = mlx_init();
	vars.height = 900;
	vars.width = 701;
	vars.height_offset = 0;
	vars.win = mlx_new_window(vars.mlx, 900, 701, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 900, 701);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	vars.img = img;
	mlx_key_hook(vars.win, move_circle, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
}
