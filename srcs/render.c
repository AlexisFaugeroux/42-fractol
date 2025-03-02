/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:32:27 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/02 14:20:06 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	compute_next_elem(t_complex *z, t_complex *c)
{
	t_complex	tmp;

	tmp.Re = z->Re;
	tmp.Im = z->Im;
	z->Re = ((z->Re * z->Re) - (z->Im * z->Im) + c->Re);
	z->Im = ((2 * tmp.Re * tmp.Im) + c->Im);
}

double	smooth_factor(t_complex z, int iteration)
{
	double	log_zn;
	double	nu;
	double	smooth;
	
	log_zn = log(z.Re * z.Re + z.Im * z.Im) / 2;
	nu = log(log_zn / log(2)) / log(2);
	smooth = iteration + 1 - nu;
	return (smooth);
}

int	get_color(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			index;
	double		smooth;
	double		t_corrected;

	z.Re = 0;
	z.Im = 0;
	c.Re = fractal->pre_computed_c[y][x].Re * fractal->zoom + fractal->offset_x;
	c.Im = fractal->pre_computed_c[y][x].Im * fractal->zoom + fractal->offset_y;
	i = 0;
	while (i < fractal->max_iter && ((z.Re * z.Re) + (z.Im * z.Im)) <= 4)
	{
		compute_next_elem(&z, &c);
		i++;
	}
	if (i == fractal->max_iter)
		return (BLACK);
	smooth = smooth_factor(z, i);
	smooth = log2(1 + smooth) / log2(fractal->max_iter);
	t_corrected = pow(smooth, 1.0 / 2.2);
	index = (int)(t_corrected * 1023);
	return (fractal->pre_computed_colors[index]);
}

void	render(t_fractal *fractal)
{
	int		x;
	int		y;
	int		color;
	t_img	*tmp;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = get_color(fractal, x, y);
			put_pixel_to_image(fractal->buffer, x, y, color);
			x++;
		}
		y++;
	}
	tmp = fractal->img;
	fractal->img = fractal->buffer;
	fractal->buffer = tmp;
	mlx_put_image_to_window(
		fractal->win->connection,
		fractal->win->win_ptr,
		fractal->img->img_ptr,
		0,
		0
		);
}
