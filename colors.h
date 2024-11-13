#ifndef COLORS_H
# define COLORS_H

typedef struct hsv_s
{
	double	h;
	double	s;
	double	v;	
	double	*p;
	double	*q;
	double	*t;
}			hsv;

typedef struct rgb_s
{
	double	r;
	double	g;
	double	b;
}			rgb;

# include <ctype.h>

uint32_t get_color_rgb(int iterations, int max_iterations);
uint32_t get_colour(int32_t r, int32_t g, int32_t b, int32_t a);

char	**get_palette(char *path, int len_palette);
void	hsv2rgb_calc_intermediate(hsv hsv_t);
void	hsv_fill_rgb(rgb *rgb_t, double hsv1, double hsv2, double hsv3);
void	hsv2rgb_handle_saturation(rgb *rgb_t, hsv hsv_t);
int		hsv2rgb_adjust_rgb(rgb rgb_t);
int		hsv2rgb(double h, double s, double v);


# define COLOR_PATH "colors.txt"
# define COLOR_MAP_LEN 754

#endif