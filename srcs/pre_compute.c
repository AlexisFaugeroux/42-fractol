/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:21:30 by alexis            #+#    #+#             */
/*   Updated: 2025/03/02 12:38:37 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	interpolate(double x, double x0, double x1, double y0, double y1)
{
	if (x1 == x0)
		return (0);
	return (y0 + (x - x0) * ((y1 - y0) / (x1 - x0)));
}

static int	interpolate_color(double t, int color_1, int color_2)
{
	int	r;
	int	g;
	int	b;
 
	r = (1 - t) * ((color_1 >> 16 & 0xFF)) + t * ((color_2 >> 16) & 0xFF);
	g = (1 - t) * ((color_1 >> 8 & 0xFF)) + t * ((color_2 >> 8) & 0xFF);
	b = (1 - t) * (color_1 & 0xFF) + t * (color_2 & 0xFF);

	return (r << 16 | g << 8 | b);
}

void	pre_compute_c(t_fractal *fractal)
{
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractal->pre_computed_c[y][x].Re = interpolate(x, 0, WIDTH, -2, 2);
			fractal->pre_computed_c[y][x].Im = interpolate(y, 0, HEIGHT, -2, 2);
			x++;
		}
		y++;
	}
}

void	pre_compute_colors(t_fractal *fractal)
{
	int		color_1;
	int		color_2;
	int		i;
	int		index_low;
	double	scaled;
	double	t;
	double	t_corrected;

	i = 0;
	while (i < 1024)
	{
		t = (double)i / 1023;
		scaled = t * (12 - 1);
		index_low = (int)scaled;
		t_corrected = scaled - index_low;
		t_corrected = pow(t_corrected, 1.0 / GAMMA);
		color_1 = fractal->palette[index_low];
		color_2 = fractal->palette[index_low + 1];
		fractal->pre_computed_colors[i] = interpolate_color(t_corrected, color_1, color_2);
		i++;
	}
}
