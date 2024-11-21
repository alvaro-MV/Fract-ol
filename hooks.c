#include "hooks.h"

void	manage_arrows(int key, mlx_vars *vars)
{
	ft_printf("key: %d\n", key);
	if (key == DOWN_ARROW)
		vars->fract->y_axis += vars->fract->axis / 3;
	else if (key == UP_ARROW)
		vars->fract->y_axis -= vars->fract->axis / 3;
	else if (key == RIGHT_ARROW)
		vars->fract->x_axis += vars->fract->axis / 3;
	else if (key == LEFT_ARROW)
		vars->fract->x_axis -= vars->fract->axis / 3;
	mlx_destroy_image(vars->mlx, vars->img.img);
	print_fractal(vars, vars->fract);
}

int	manage_keys(int key, mlx_vars *vars)
{
	if (key == 65307) //escape
		close_win(vars);
	// else if (key == 105) // letra i: cambiar color del set fractal
	// {
	// 	mlx_destroy_image(vars->mlx, vars->img.img);
	// 	vars->fract->max_iter += 1000;
	// 	print_fractal(vars, vars->fract);
	// }
	else if (key == O_KEY)
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		vars->fract->color_offset += 0x00214112;
		print_fractal(vars, vars->fract);
	}
	else if (key >= LEFT_ARROW && key <= DOWN_ARROW)
		manage_arrows(key, vars);
	return (0);
}

int	manage_mouse(int button, int x, int y, mlx_vars *vars)
{
	fractal	*frac;

	printf("x: %d,  y: %d\n", x, y);
	printf("button: %d\n", button);
	frac = vars->fract;
	if (button == 4)
	{
		frac->x_axis += x * (frac->axis / frac->win_h) - frac->axis / 4;
		frac->y_axis += y * (frac->axis / frac->win_h) - frac->axis / 4;
		frac->axis /= 1.5;
		mlx_destroy_image(vars->mlx, vars->img.img);
		print_fractal(vars, vars->fract);
	}
	else if (button == 5)
	{
		frac->x_axis -= x * (frac->axis / frac->win_h) - frac->axis / 4;
		frac->y_axis -= y * (frac->axis / frac->win_h) - frac->axis / 4;
		frac->axis *= 1.5;
		mlx_destroy_image(vars->mlx, vars->img.img);
		print_fractal(vars, vars->fract);
	}
	return (0);
}
