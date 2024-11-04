#include <stdio.h>

static void	calc_decimal(double *value, char *str)
{
	double	dec_idx;

	dec_idx = 10;
	while (*str >= '0' && *str <= '9')
	{
		*value = *value + (*str - '0') / dec_idx;
		dec_idx *= 10;
		str++;
	}
}

double	ft_atof(char *str)
{
	int		signo;
	double	value;

	value = 0;
	signo = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signo++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = (*str - '0') + value * 10;
		str++;
	}
	if (*str++ == '.')
		calc_decimal(&value, str);
	if (signo % 2 != 0)
		value *= -1;
	return (value);
}
