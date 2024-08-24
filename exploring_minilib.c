#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include "lib/include/libft.h"

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
}			mlx_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
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
#include <limits.h>
void	add_shade(double distance, int *color)
{
	int map;

	if (distance < 0 || distance > 1)
		return ;
	map = (int) distance * 0x100;
	map = ((0xFF * map) / 0x100) << 24;
	*color = *color & 0xFFFFFF;
	*color = *color + map;	
}

int	close_win(int	keymap, mlx_vars *vars)
{
	if (keymap == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	close_win_cross(int x, int y, mlx_vars *vars)
{
	write(1, "HOOOOOOLLLAA", 6);
	//ft_printf("location  x: %d  y: %d\n", x, y);
	return (0);
}

int	window_resize(mlx_vars *vars)
{
	write(1, "window resized", 15);
	return (0);
}

int	main(void)
{
	mlx_vars	vars;
	t_data		img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
//	int	radius =20000;
	//int	centrus = 600;
	//int color = 0x00904428;
	//double	i = 10;
	//while (i--)
	//{
		////add_shade(i/10, &color);
		//color = color + 0x07000000;
		//radius -= 100;
		//print_circle(centrus, radius, color, img);
	//}
	//mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 4, 1L<<2, close_win_cross, &vars);
	mlx_loop(vars.mlx);
}

