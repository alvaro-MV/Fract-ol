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
	double	axis_correction;
	static int	zoom;

	printf("button: %d\n", button);
	if (zoom == 0)
		zoom = 1;
	frac = vars->fract;
	if (button == 1)
	{
		printf("x re: %lf,  y im: %lf\n", x * (frac->axis_range / frac->win_height),  y * (frac->axis_range / frac->win_height));
		axis_correction = 0.2;
		frac->x_axis += x * (frac->axis_range / frac->win_height) - axis_correction;
		frac->y_axis += y * (frac->axis_range / frac->win_height) - axis_correction;
		frac->axis_range /= zoom;
		mlx_destroy_image(vars->mlx, vars->img.img);
		print_fractal(vars, vars->fract);
		zoom++;
	}
	return (0);
}
