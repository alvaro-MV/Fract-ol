#include "hooks.h"

void	manage_arrows(int keymap, mlx_vars *vars)
{
	if (keymap == 65364) //flecha hacia abajo: mover el fractal hacia abajo.
		vars->fract->y_axis -= 0.3;
	else if (keymap == 65362) //flecha hacia arriba: mover hacia arriba.
		vars->fract->y_axis += 0.3;
	else if (keymap == 65363) //flecha hacia la derecha: ...
		vars->fract->x_axis -= 0.3;
	else if (keymap == 65361) //flecha hacia la izq: ...
		vars->fract->x_axis += 0.3;
	mlx_destroy_image(vars->mlx, vars->img.img);
	print_fractal(vars, vars->fract);
}

int	manage_keys(int keymap, mlx_vars *vars)
{
	ft_printf("keys: %d\n", keymap);
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
	else if (keymap >= 65361 && keymap <= 65364)
		manage_arrows(keymap, vars);
	//else if (keymap == 65289) //tab: para cambiar el fractal.
	return (0);
}

int	manage_mouse(int button, int x, int y, mlx_vars *vars)
{
	fractal	*frac;

	printf("button: %d\n", button);
	frac = vars->fract;
	if (button == 1)
	{
		printf("x re: %lf,  y im: %lf\n", x * (frac->axis_range / frac->win_height),  y * (frac->axis_range / frac->win_height));
		frac->x_axis += x * (frac->axis_range / frac->win_height) - frac->axis_range / 4;
		frac->y_axis += y * (frac->axis_range / frac->win_height) - frac->axis_range / 4;
		frac->axis_range /= 2;
		mlx_destroy_image(vars->mlx, vars->img.img);
		print_fractal(vars, vars->fract);
	}
	return (0);
}
