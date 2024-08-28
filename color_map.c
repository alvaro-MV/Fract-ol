#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "lib/include/libft.h"
#include "lib/include/get_next_line.h"
#include "fract-ol.h"
#include <math.h>

char	**get_palette(char *path, int len_palette)
{
	char	**palette;
	char	*color;
	int		palette_fd;
	int		i;

	i = 0;
	palette_fd = open(path, O_RDONLY);
	if (palette_fd == -1)
		return (NULL);
	palette = (char **) malloc((len_palette + 1) * sizeof(char *));
	if (palette == NULL)
		return (NULL);
	while (i < len_palette)
	{
		color = get_next_line(palette_fd);
		if (color == NULL)
			break ;
		palette[i] = color;
		i++;
	}
	palette[i] = NULL;
	close(palette_fd);
	return (palette);
}

//int	main(void)
//{
	//char	*path = "colors.txt";
	//char	**palette = get_palette(path, COLOR_MAP_LEN);
	//int		i = 0;

	//while (palette[i])
	//{
		//ft_printf("%d)) palette color: %s\n", i, palette[i]);
		//i++;
	//}
	//ft_free_array(palette);
	//return (0);
//}
