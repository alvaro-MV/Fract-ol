
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

int	print_mandel(mlx_vars *vars, fractal fract)
{
	int		i;
	int 	j;
	int		color;
	char	**palette;
	complex	c;
	int counter = 0;

	palette = get_palette(COLOR_PATH, COLOR_MAP_LEN);
	c.re = fract.x_axis;
	i = 0;
	while (i < WIN_HEIGHT * 3)
	{
		c.im = fract.y_axis;
		j = 0;
		while (j < WIN_WIDTH * 3)
		{
			printf("re  : %lf,    im: %lf\n", c.re, c.im);
			color = ft_xtoi(palette[get_iteration(c) % COLOR_MAP_LEN]);
			print_pixel(vars->img, i, j, color);
			c.im += fract.width_incr;
			j++;
		}
		c.re += fract.heigth_incr;
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	ft_free_array(palette);
	return (0);
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
	fractal		fract;

	vars.mlx = mlx_init();
	vars.height = WIN_HEIGHT;
	vars.width = WIN_WIDTH;
	vars.height_offset = 0;
	vars.win = mlx_new_window(vars.mlx, (3 * WIN_HEIGHT), (3 * WIN_WIDTH), "Hello world!");
	img.img = mlx_new_image(vars.mlx, (3 * WIN_HEIGHT), (3 * WIN_WIDTH));
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	vars.img = img;
	init_fractal(&fract);
	print_mandel(&vars, fract);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
}
