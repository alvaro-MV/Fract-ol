#include "fract-ol.h"
#include "colors.h"

//char	**get_palette(char *path, int len_palette)
//{
	//char	**palette;
	//char	*color;
	//int		palette_fd;
	//int		i;

	//i = 0;
	//palette_fd = open(path, O_RDONLY);
	//if (palette_fd == -1)
		//return (NULL);
	//palette = (char **) malloc((len_palette + 1) * sizeof(char *));
	//if (palette == NULL)
		//return (NULL);
	//while (i < len_palette)
	//{
		//color = get_next_line(palette_fd);
		//if (color == NULL)
			//break ;
		//palette[i] = color;
		//i++;
	//}
	//palette[i] = NULL;
	//close(palette_fd);
	//return (palette);
//}

// IMplementation of hsv to rgb mapping.

void hsv2rgb_calc_intermediate(hsv hsv_t)
{
    double	f;
	int		i;

    hsv_t.h /= 60;
    i = (int)hsv_t.h;
    f = hsv_t.h - i;

    *(hsv_t.p) = hsv_t.v * (1 - hsv_t.s);
    *(hsv_t.q) = hsv_t.v * (1 - hsv_t.s * f);
    *(hsv_t.t) = hsv_t.v * (1 - hsv_t.s * (1 - f));
}

void	hsv_fill_rgb(rgb *rgb_t, double hsv1, double hsv2, double hsv3)
{
	rgb_t->r = hsv1;
	rgb_t->g = hsv2;
	rgb_t->b = hsv3;
}

void hsv2rgb_handle_saturation(rgb *rgb_t, hsv hsv_t)
{
	int i;

	i = (int) hsv_t.h;
    if (i == 0)
		hsv_fill_rgb(rgb_t, hsv_t.v, *hsv_t.t, *hsv_t.p);
    else if (i == 1) 
		hsv_fill_rgb(rgb_t, *hsv_t.q, hsv_t.v, *hsv_t.p);
    else if (i == 2)
		hsv_fill_rgb(rgb_t, *hsv_t.p, hsv_t.v, *hsv_t.t);
    else if (i == 3)
		hsv_fill_rgb(rgb_t, *hsv_t.p, *hsv_t.q, hsv_t.v);
    else if (i == 4)
		hsv_fill_rgb(rgb_t, *hsv_t.t, *hsv_t.p, hsv_t.v);
    else
		hsv_fill_rgb(rgb_t, hsv_t.v, *hsv_t.p, *hsv_t.q);
}

int hsv2rgb_adjust_rgb(rgb rgb_t)
{
	int	r_l;
	int	g_l;
	int	b_l;

	r_l = (int)(rgb_t.r * 255);
	g_l = (int)(rgb_t.g * 255);
	b_l = (int)(rgb_t.b * 255);
	return (r_l << 16 | g_l << 8 | b_l);
}

// Main hsv2rgb function
int	hsv2rgb(double h, double s, double v)
{
	rgb	rgb_color;
	hsv	hsvpqt;

	if (s == 0) {
        rgb_color.r = v;
        rgb_color.g = v;
        rgb_color.b = v;
        return (0);
    }
	hsvpqt.h = h;
	hsvpqt.s = s;
	hsvpqt.v = v;
	hsvpqt.p = (double *) malloc(1 * sizeof(double));
	hsvpqt.q = (double *) malloc(1 * sizeof(double));
	hsvpqt.t = (double *) malloc(1 * sizeof(double));
    hsv2rgb_calc_intermediate(hsvpqt);
    hsv2rgb_handle_saturation(&rgb_color, hsvpqt);
	free(hsvpqt.p);
	free(hsvpqt.q);
	free(hsvpqt.t);
    return (hsv2rgb_adjust_rgb(rgb_color));
}
