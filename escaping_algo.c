
#include "fract-ol.h"

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

void	print_pixel(t_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	* (unsigned int *) dst = color;
}

int	print_mandel(mlx_vars *vars)
{
	double 	i;
	double 	j;
	int		color;
	char	*palette;
	complex	c;

	i = 0;
	j = 0;
	
	palette = get_palette(COLOR_PATH, COLOR_MAP_LEN);
	while (j < WIN_HEIGHT)
	{
		while (i < WIN_WIDTH)
		{
			c.re = i;
			c.im = j;
			color = ft_atoi(palette[get_iteration(c, COLOR_MAP_LEN - 1)]);
			print_pixel(vars->img, i, j, color);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	ft_free_array(palette);
	return (0);
}

int	main(void)
{
	mlx_vars	vars;
	t_data		img;
	char		*relative_path;
	complex		c;
	fractal		fract;

	vars.mlx = mlx_init();
	vars.height = 900;
	vars.width = 701;
	vars.height_offset = 0;
	vars.win = mlx_new_window(vars.mlx, 900, 701, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 900, 701);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	vars.img = img;
	print_mandel(&vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
}
