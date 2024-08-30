#include "hooks.h"

int	manage_keys(int keymap, mlx_vars *vars)
{
	if (keymap == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	else if (keymap == 105) // letra i: cambiar color del set fractal
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		vars->fract->max_iter += 1000;
		print_fractal(vars, vars->fract);
	}
	else if (keymap == 111) // letra o: cambiar color fuera set fract.
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		vars->fract->color_offset += 100;
		print_fractal(vars, vars->fract);
	}
	//else if (keymap == 65289) //tab: para cambiar el fractal.
	//else if (keymap == 65364) //flecha hacia abajo: mover el fractal hacia abajo.
	//else if (keymap == 65362) //flecha hacia arriba: mover hacia arriba.
	//else if (keymap = 65363) //flecha hacia la derecha: ...
	//else if (keymap = 65361) //flecha hacia la izq: ...
	return (0);
}
