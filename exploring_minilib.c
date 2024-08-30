#include "mlx.h"
#include "mlx_int.h"
#include <unistd.h>
#include <stdio.h>
#include "lib/include/libft.h"
#include "fract-ol.h"
#include <math.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_scape(mlx_vars *vars, int i, int j, int sizze)
{
	double	re, im;
	int		iter;
	double	z_real, z_imag;
	double	temp;

	re = -2.0 + j * (3.0 / 900.0);
	im = -1.5 + i * (3.0 / 900.0);

	//printf("c real: %lf   c im: %lf\n", c_real, c_imag);
	iter = 0;
	z_real = 0;
	z_imag = 0;
	while (iter < 20 && z_real * z_real + z_imag * z_imag < 4.0) {
		temp = z_real * z_real - z_imag * z_imag + re;
		z_imag = 2 * z_real * z_imag + im;
		z_real = temp;
		iter++;
	}
	printf("iter: %d\n", iter);
	if (iter == 20)
		return (0x0);
	else
		return (0x00ffffff);
}

int	print_mandel(mlx_vars *vars, int sizze)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->img.img = mlx_new_image(vars->mlx, sizze, sizze);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
							&vars->img.endian);
    while (i < sizze) 
	{
		j = 0;
		while (j < sizze)
		{
			my_mlx_pixel_put(&vars->img, i, j, get_scape(vars, i, j, sizze));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0,0);
}

int	print_key(int keycode, mlx_vars *vars)
{
	printf("key: %d\n", keycode);
	return (0);
}

//int	main(void)
//{
	//mlx_vars	vars;
	//t_data		img;
	//int			sizze = 900;	

	//vars.mlx = mlx_init();
	//vars.height = sizze;
	//vars.width = sizze;
	//vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	//print_mandel(&vars, sizze);
	//mlx_key_hook(vars.win, print_key, &vars);
	//mlx_loop(vars.mlx);
	////mlx_destroy_window(vars.mlx, vars.win);
//}

