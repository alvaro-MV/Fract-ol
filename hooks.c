#include "hooks.h"

void	manage_arrows(int key, mlx_vars *vars)
{
	if (key == 65364) //flecha hacia abajo: mover el fractal hacia abajo.
		vars->fract->y_axis += vars->fract->axis_range / 3;
	else if (key == 65362) //flecha hacia arriba: mover hacia arriba.
		vars->fract->y_axis -= vars->fract->axis_range / 3;
	else if (key == 65363) //flecha hacia la derecha: ...
		vars->fract->x_axis += vars->fract->axis_range / 3;
	else if (key == 65361) //flecha hacia la izq: ...
		vars->fract->x_axis -= vars->fract->axis_range / 3;
	mlx_destroy_image(vars->mlx, vars->img.img);
	print_fractal(vars, vars->fract);
}

int	manage_keys(int key, mlx_vars *vars)
{
	if (key == 65307) //escape
		mlx_destroy_window(vars->mlx, vars->win);
	else if (key == 105) // letra i: cambiar color del set fractal
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		vars->fract->max_iter += 1000;
		print_fractal(vars, vars->fract);
	}
	else if (key == 111) // letra o: cambiar color fuera set fract.
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		vars->fract->color_offset += 0x00111112;
		print_fractal(vars, vars->fract);
	}
	else if (key >= 65361 && key <= 65364)
		manage_arrows(key, vars);
	//else if (keymap == 65289) //tab: para cambiar el fractal.
	return (0);
}

int	manage_mouse(int button, int x, int y, mlx_vars *vars)
{
	fractal	*frac;

	frac = vars->fract;
	ft_printf("button: %d\n", button);
	if (button == 4)
	{
		frac->x_axis += x * (frac->axis_range / frac->win_height) - frac->axis_range / 3;
		frac->y_axis += y * (frac->axis_range / frac->win_height) - frac->axis_range / 3;
		frac->axis_range /= 1.5;
		mlx_destroy_image(vars->mlx, vars->img.img);
		print_fractal(vars, vars->fract);
	}
	else if (button == 5)
	{
		frac->x_axis -= x * (frac->axis_range / frac->win_height) - frac->axis_range / 3;
		frac->y_axis -= y * (frac->axis_range / frac->win_height) - frac->axis_range / 3;
		frac->axis_range *= 1.5;
		mlx_destroy_image(vars->mlx, vars->img.img);
		print_fractal(vars, vars->fract);
	}
	return (0);
}
