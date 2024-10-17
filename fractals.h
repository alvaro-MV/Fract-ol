#ifndef FRACTALS_H
# define FRACTALS_H

# include "fract-ol.h"
# include <float.h>

int	scape_mandelbrot(int i, int j, void *vfract);
int	scape_julia(int i, int j, void *vfract);
int	scape_burning_ship(int i, int j, void *vfract);
//int	scape_julia_sets(int i, int j, void *vfract);
int	scape_lyapunov(int i, int j, void *vfract);

#endif
