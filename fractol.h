/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:43:49 by alvmoral          #+#    #+#             */
/*   Updated: 2024/12/02 19:56:10 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "mlx_int.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/include/libft.h"
# include "libft/include/get_next_line.h"
# include "colors.h"
# include <math.h>
# include <limits.h>

typedef int	(*t_scape_func) (int i, int j, void *fract);

typedef struct complex_number
{
	double	re;
	double	im;
}			t_complex;

typedef struct fract_ol
{
	double			x_axis;
	double			y_axis;
	double			axis;
	int				color_offset;
	int				win_h;
	int				win_w;
	int				max_iter;
	int				iter;
	t_scape_func	fractal_func;
	double			j_real;
	double			j_im;
}					t_fractal;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct var_mlx
{
	void		*win;
	void		*mlx;
	t_data		img;
	int			height;
	int			width;
	t_fractal	*fract;
}				t_mlx_vars;

# define WIN_HEIGHT 900
# define WIN_WIDTH 900

# define MAX_ITER 30

double	ft_atof(char *str);
int		parse_params(char **argv, t_fractal *fract);
int		close_win(t_mlx_vars *vars);

void	print_pixel(t_data img, int x, int y, int color);
void	print_fractal(t_mlx_vars *vars, t_fractal *fract);
void	init_fractal(t_mlx_vars *vars, char **argv);

#endif