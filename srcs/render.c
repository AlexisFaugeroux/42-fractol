/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:32:27 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/28 17:37:41 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	interpolate(double x, double x0, double x1, double y0, double y1)
{
	if (x1 == x0)
		return (0);
	return (y0 + (x - x0) * ((y1 - y0) / (x1 - x0)));
}

void	compute_next_elem(t_complex *z, t_complex *c)
{
	t_complex	tmp;

	tmp.Re = z->Re;
	tmp.Im = z->Im;
	z->Re = (z->Re * z->Re) - (z->Im * z->Im) + c->Re;
	z->Im = (2 * tmp.Re * tmp.Im) + c->Im;
}

double	modulo(double Re, double Im)
{
	return (sqrt((Re * Re) + (Im * Im)));
}

int	compute(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			k;

	z.Re = 0;
	z.Im = 0;
	c.Re = interpolate(x, 0, WIDTH, -2, 2);
	c.Im = interpolate(y, 0, HEIGHT, -2, 2);
	/* printf("RE: %lf\n", c.Re);
	printf("IM: %lf\n", c.Im); */
	color = 0XFFFFFFFF;
	k = 0;
	while (k < fractal->max_iter)
	{
		if (modulo(z.Re, z.Im) > 2)
		{
			color = 0X00000000;
			break ;
		}
		compute_next_elem(&z, &c);
		k++;
	}
	return (color);
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
