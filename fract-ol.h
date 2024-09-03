#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx.h"
# include "mlx_int.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "lib/include/libft.h"
# include "lib/include/get_next_line.h"
# include "colors.h"
# include <math.h>

typedef struct complex_number
{
    double re;
    double im;   
}   complex;

typedef struct fract_ol
{
    double  x_axis;
    double  y_axis;
	double	axis_range;
	int		color_offset;
	int		win_height;
	int		win_width;
	int		max_iter;
	int		(*fractal_func[2])();
}           fractal;

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
	fractal	*fract;
}			mlx_vars;

# define WIN_HEIGHT 900
# define WIN_WIDTH 900

# define MAX_ITER 3278

int	    ft_xtoi(char *str);

//Escaping algo
void	print_pixel(t_data img, int x, int y, int color);
void	print_fractal(mlx_vars *vars, fractal *fract);
void	init_fractal( fractal *fract);


#endif