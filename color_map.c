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

int	get_rgb_hsv(double r_hsv, double g_hsv, double b_hsv)
{
	int	color;
	
}

int	hsv2rgb(double hue, double s, double v)
{
	int 	i;
	double	hsv_vars[4];

	hue /= 60;
    i = (int)hue;
	hsv_vars[0] = hue - i; //f
	hsv_vars[1] = v * (1 - s); //p
	hsv_vars[2] =  v * (1 - s * hsv_vars[0]); //q
	hsv_vars[2] =  v * (1 - s * (1- hsv_vars[0])); //t
	if (i = 0)
		return (get_rgb_hsv(hsv_vars));

	       case 0: *r = v; *g = t; *b = p; break;
        case 1: *r = q; *g = v; *b = p; break;
        case  
 2: *r = p; *g = v; *b = t; break;
        case 3: *r = p; *g = q; *b = v; break;
        case 4: *r = t; *g = p; *b = v; break;
        default: *r = v; *g = p; *b = q; 
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
