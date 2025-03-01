/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:32:27 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/01 18:04:59 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	interpolate(double x, double x0, double x1, double y0, double y1)
{
	if (x1 == x0)
		return (0);
	return (y0 + (x - x0) * ((y1 - y0) / (x1 - x0)));
}

int	interpolate_color(double t, int color_1, int color_2)
{
	int	r;
	int	g;
	int	b;
 
	r = (1 - t) * ((color_1 >> 16 & 0xFF)) + t * ((color_2 >> 16) & 0xFF);
	g = (1 - t) * ((color_1 >> 8 & 0xFF)) + t * ((color_2 >> 8) & 0xFF);
	b = (1 - t) * (color_1 & 0xFF) + t * (color_2 & 0xFF);

	return (r << 16 | g << 8 | b);
}

/* int	clamp(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

int gamma_interpolate(double t, int color_1, int color_2)
{
	double r1;
	double r2;
	double r;
	double g1;
	double g2;
	double g;
	double b1;
	double b2;
	double b;

	r1 = pow(((color_1 >> 16) & 0xFF) / 255.0, GAMMA);
	r2 = pow(((color_2 >> 16) & 0xFF) / 255.0, GAMMA);
	r = pow((1 - t) * r1 + t * r2, 1.0 / GAMMA) * 255;
	r = clamp(r, 0, 255);
	g1 = pow(((color_1 >> 8) & 0xFF) / 255.0, GAMMA);
	g2 = pow(((color_2 >> 8) & 0xFF) / 255.0, GAMMA);
	g = pow((1 - t) * g1 + t * g2, 1.0 / GAMMA) * 255;
	g = clamp(g, 0, 255);
	b1 = pow(((color_1) & 0xFF) / 255.0, GAMMA);
	b2 = pow(((color_2) & 0xFF) / 255.0, GAMMA);
	b = pow((1 - t) * b1 + t * b2, 1.0 / GAMMA) * 255;
	b = clamp(b, 0, 255);
	return ((int)r << 16 | (int)g << 8 | (int)b);
} */

void	compute_next_elem(t_complex *z, t_complex *c)
{
	t_complex	tmp;

	tmp.Re = z->Re;
	tmp.Im = z->Im;
	z->Re = ((z->Re * z->Re) - (z->Im * z->Im) + c->Re);
	z->Im = ((2 * tmp.Re * tmp.Im) + c->Im);
}

double	modulo(double Re, double Im)
{
	return (sqrt((Re * Re) + (Im * Im)));
}

double	smooth_factor(t_complex z, int iteration)
{
	double	log_zn;
	double	nu;
	double	smooth;
	
	log_zn = log(z.Re * z.Re + z.Im * z.Im) / 2.0;
	nu = log(log_zn / log(2)) / log(2);
	smooth = iteration + 1 - nu;
	return (smooth);
}

int	compute(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color_1;
	int			color_2;
	double		smooth;
	double		t;

	z.Re = 0;
	z.Im = 0;
	c.Re = interpolate(x, 0, WIDTH, -2, 2) * fractal->zoom;
	c.Im = interpolate(y, 0, HEIGHT, -2, 2) * fractal->zoom;
	i = 0;
	while (i < fractal->max_iter && modulo(z.Re, z.Im) <= 2)
	{
		compute_next_elem(&z, &c);
		i++;
	}
	if (i == fractal->max_iter)
		return (0x00000000);
	smooth = smooth_factor(z, i);
	color_1 = fractal->colors[(int)smooth % 12];
	color_2 = fractal->colors[((int)smooth + 1) % 12];
	t = smooth - (int)smooth;
	return (interpolate_color(t, color_1, color_2));
}

void	render(t_fractal *fractal)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = compute(fractal, x, y);
			put_pixel_to_image(fractal->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(
		fractal->win->connection,
		fractal->win->win_ptr,
		fractal->img->img_ptr,
		0,
		0
		);
}
