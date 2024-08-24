#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include "lib/include/libft.h"
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
	ft_printf("dst: %d\n", dst);
	*(unsigned int*)dst = color;
}

void	print_circle(int centrus, int radius, int color, t_data img)
{
	int i, j = centrus - radius;
	while (i < centrus + radius)
	{
		j  = centrus - radius;
		while (j < centrus)
		{
			if ((i - centrus)*(i - centrus) + (j - centrus)*(j - centrus) > radius - radius/3
				&& (i - centrus)*(i - centrus) + (j - centrus)*(j - centrus) < radius + radius/3)
				my_mlx_pixel_put(&img, i, j, color);
			j++;
		}
		i++;
	}
}

int	print_line(int keymap, mlx_vars *vars)
{
	int	j = 0;

	if (keymap == 65364)
	{
		while (j < vars->width)
		{
			//ft_printf("column: %d\n", j);
			my_mlx_pixel_put(&vars->img, j, vars->height_offset, 0x00FF0000);
			j++;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, &vars->img, 0, 0);
		vars->img.img = mlx_new_image(vars->mlx, 900, 800);
		vars->height_offset++;
	}
	return (0);
}

int	main(void)
{
	mlx_vars	vars;
	t_data		img;

	vars.mlx = mlx_init();
	vars.height = 800;
	vars.width = 900;
	vars.height_offset = 0;
	vars.win = mlx_new_window(vars.mlx, 900, 800, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 900, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	vars.img = img;
	mlx_key_hook(vars.win, print_line, &vars);
	mlx_loop(vars.mlx);
}

