#ifndef HOOKS_H
# define HOOKS_H

# include "fract-ol.h"

# define ESCAPE 65307
# define O_KEY 111
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define UP_ARROW 65362
# define DOWN_ARROW 65364

int	manage_keys(int keymap, mlx_vars *vars);
int	manage_mouse(int button, int x, int y, mlx_vars *vars);

#endif