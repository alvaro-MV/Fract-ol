
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
	int 	i;
	int 	j;
	int		color;
	char	**palette;
	complex	c;
	int counter = 0;

	palette = get_palette(COLOR_PATH, COLOR_MAP_LEN);
	c.re = fract.left_end;
	c.im = fract.left_end;
	printf("c re: %lf,  c im: %lf\n", c.re, c.im);
	i = 0;
	while (i < WIN_WIDTH)
	{
		printf("c re: %lf,  c im: %lf\n", c.re, c.im);
		counter = get_iteration(c, MAX_ITER);
		ft_printf("counter: %d\n", counter);
		print_pixel(vars->img, 23, i, counter);
		c.re += fract.width_incr;
		c.im += fract.heigth_incr;
		i++;
	}
//	while (i < WIN_HEIGHT)
	//{
		//c.im = fract.left_end;
		//j = 0;
		//while (j < WIN_WIDTH)
		//{
			//ft_printf("i:  %d,   j: %d\n", i, j);
			//color = ft_xtoi(palette[get_iteration(c, MAX_ITER)]);
			//ft_printf("color:  %d\n", color);
			//print_pixel(vars->img, i, j, color);
			//c.im += fract.width_incr;
			//j++;
		//}
		//c.re += fract.heigth_incr;
		//i++;
	//}
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
	vars.height = WIN_HEIGHT;
	vars.width = WIN_WIDTH;
	vars.height_offset = 0;
	vars.win = mlx_new_window(vars.mlx, WIN_HEIGHT, WIN_WIDTH, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 900, 701);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	vars.img = img;
	fract.right_end = 2;
	fract.left_end = -2;
	get_size_increment(&fract);
	print_mandel(&vars, fract);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
}
