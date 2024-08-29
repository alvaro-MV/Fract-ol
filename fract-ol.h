#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx.h"
# include "mlx_int.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "lib/include/libft.h"
# include "lib/include/get_next_line.h"
#include <math.h>

typedef struct complex_number
{
    double re;
    double im;   
}   complex;

typedef struct fract_ol
{
    double  heigth_incr;
    double  width_incr;
    double  right_end;
    double  left_end;
}           fractal;

# define WIN_HEIGHT 900
# define WIN_WIDTH 701

# define MAX_ITER 754

complex *get_mandelbrot_set(complex c, int len);
int     get_next_mand_n(complex c, complex *z_n, int *iteration);
int	    get_iteration(complex c);
void	get_size_increment(fractal *fract);
int	    ft_xtoi(char *str);

//Colors
char	**get_palette(char *path, int len_palette);

# define COLOR_PATH "colors.txt"
# define COLOR_MAP_LEN 754

#endif