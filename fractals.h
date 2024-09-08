#ifndef FRACTALS_H
# define FRACTALS_H

# include "fract-ol.h"

int	scape_mandelbrot(int i, int j, fractal *fract);
int	scape_julia(int i, int j, fractal *fract);
int	scape_burning_ship(int i, int j, fractal *fract);
int	scape_julia_sets(int i, int j, fractal *fract);

#endif
