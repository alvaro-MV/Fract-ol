#ifndef FRACT_OL_H
# define FRACT_OL_H

typedef struct complex_number
{
    double re;
    double im;   
}   complex;

# define WIN_HEIGHT 900
# define WIN_WIDTH 701

# define MAX_ITER 275
# define COLOR_MAP_LEN 275
# define LEN_COLOR_FD 2662

complex *get_mandelbrot_set(complex c, int len);
int     get_next_mand_n(complex c, complex *z_n, int max_iteration);
int	    get_iteration(complex c, int max_iter);



#endif