#include "fract-ol.h"

int	manage_keys(int keymap, mlx_vars *vars)
{
	if (keymap = 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	else if (keymap ==)
}

void	manage_hooks(mlx_vars *vars)
{
	mlx_key_hook(vars->mlx, manage_keys, &vars);
}