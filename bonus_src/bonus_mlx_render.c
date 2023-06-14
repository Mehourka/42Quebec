#include "bonus_fractol.h"

typedef struct color{
	int r;
	int g;
	int b;
	int a;
}	color_t;

double mod2(double v[2])
{
	return (v[0] * v[0] + v[1] * v[1]);
}
int norm_rgba(float r, float g, float b, float a)
{
	r = fmin(fmax(r, 0), 1) * 255;
	g = fmin(fmax(g, 0), 1) * 255;
	b = fmin(fmax(b, 0), 1) * 255;
	a = fmin(fmax(a, 0), 1) * 255;

    return ((int)r << 24 |(int) g << 16 |(int) b << 8 |(int) a);
}

int get_rgba(int r, int g, int b, int a)
{

    return (r << 24 | g << 16 | b << 8 | a);
}

void rgba_from_int(color_t *struc, int32_t color)
{
	struc->r = color >> 24 & 255;
	struc->g = color >> 16 & 0xFF;
	struc->b = color >> 8 & 0xFF;
	struc->a = color & 0xAF;
}

int map_color(int32_t color1, int32_t color2, double s)
{
	color_t col1;
	color_t col2;
	color_t	new;

	rgba_from_int(&col1, color1);
	rgba_from_int(&col2, color2);
	new.r = (-col1.r + col2.r) * s + col2.r;
	new.g = (-col1.g + col2.g) * s + col2.g;
	new.b = (-col1.b + col2.b) * s + col2.b;
	new.a = (-col1.a + col2.a) * s + col2.a;

	return get_rgba(new.r, new.g, new.b, new.a);
}

float palette_function(float d, float t)
{
	return (0.5 + 0.5 * cos(M_PI * 2 * (1.0 * t + d)));
}

int color_palette(float t)
{
	float r = palette_function(-0.721, t);//(0.263, t);
	float g = palette_function(-0.493, t);//(0.416, t);
	float b = palette_function(-0.353, t);//(0.557, t);

	return norm_rgba(r, g, b, 1);
}

void render_pixel(mlx_image_t *img, int i, int j, double num_iter)
{
	t_data *data = init_data();
	int max_iter = data->max_iter;
	int32_t	color;

	double d = ft_map((double) num_iter, (double[]){0, max_iter}, (double[]){0, 1});
	static double shift = 0;
	if(mlx_is_key_down(data->mlx, MLX_KEY_C))
	{
		shift += pow(10, -7);
		if(shift > 1)
			shift = 0;
	}

	d = pow(d, 0.4);
	color = color_palette(d + shift);
	if (num_iter == max_iter)
		mlx_put_pixel(img, i, j, BLACK);
	else
		mlx_put_pixel(img, i, j, color);
}


void render_pixel_original(mlx_image_t *img, int i, int j, double num_iter)
{
	t_data *data = init_data();
	int max_iter = data->max_iter;
	int32_t	color;

	double hue = ft_map((double) num_iter, (double[]){0, max_iter}, (double[]){-M_PI / 2, M_PI / 2});
	static double shift = -0.5;
	if(mlx_is_key_down(data->mlx, MLX_KEY_C))
	{
		shift += pow(10, -6.5);
		if(shift > M_PI)
			shift = -M_PI;
	}
	color = get_rgba(\
		0.5 * (sin(hue + shift) + 1) * 255,\
		0.5 * (sin(hue + shift + M_PI / 3) + 1) * 255,\
		0.5 * (sin(hue + 0.5 * shift + M_PI / 3) + 1) * 255,\
		255);
	if (num_iter == max_iter)
		mlx_put_pixel(img, i, j, BLACK);
	else
		mlx_put_pixel(img, i, j, color);
}