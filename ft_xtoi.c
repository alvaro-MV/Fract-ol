#include "lib/include/libft.h"
#include <stdio.h>

int	valid_char(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'f')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	get_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'b' || c == 'B')
		return (11);
	else if (c == 'c' || c == 'c')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else if (c == 'f' || c == 'F')
		return (15);
	else
		return (-1);
}

int	ft_xtoi(char *str)
{
	int	signo;
	int	value;

	value = 0;
	signo = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (!ft_strncmp(str, "0x", 2))
		str += 2;
	while (valid_char(*str))
	{
		value = get_value(*str) + value * 16;
		if (value == 1)
			break ;
		str++;
	}
	return (value);
}
