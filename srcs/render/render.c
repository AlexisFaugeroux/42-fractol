/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:32:27 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/03 20:39:57 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"
#include "../includes/utils.h"

static void	compute_next_elem(t_complex *z, t_complex *c)
{
	t_complex	tmp;

	tmp.Re = z->Re;
	tmp.Im = z->Im;
	z->Re = ((z->Re * z->Re) - (z->Im * z->Im) + c->Re);
	z->Im = ((2 * tmp.Re * tmp.Im) + c->Im);
}

static int	compute_color(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			index;
	double		smooth;

	z.Re = 0;
	z.Im = 0;
	c.Re = fractal->pre_computed_c[y][x].Re * fractal->zoom + fractal->offset_x;
	c.Im = fractal->pre_computed_c[y][x].Im * fractal->zoom + fractal->offset_y;
	i = 0;
	while (i < fractal->max_iter && ((z.Re * z.Re) + (z.Im * z.Im)) <= 4)
	{
		compute_next_elem(&z, &c);
		fractal->op_count += OP_PER_COMPUTE;
		i++;
	}
	if (i == fractal->max_iter)
		return (BLACK);
	fractal->escaped[y * WIDTH + x] = true;
	smooth = smooth_factor(z, i);
	smooth = log2(1 + smooth) / log2(fractal->max_iter);
	index = (int)(smooth * 1023);
	return (fractal->pre_computed_colors[index]);
}

static void	stop_calc_and_render(t_fractal * fractal, int x, int y)
{
	fractal->last_computed_y = y;
	fractal->last_computed_x = x;
	/* if (fractal->last_computed_x >= WIDTH)
	{
		fractal->last_computed_y++;
		fractal->last_computed_x = 0;
	} */
	mlx_put_image_to_window(fractal->win->connection, fractal->win->win_ptr,
			fractal->img->img_ptr, 0, 0);
	fractal->op_count = 0;
}

static void	put_image(t_fractal *fractal)
{
	if (fractal->max_iter <= 206)
		fractal->max_iter += 50;
	mlx_put_image_to_window(fractal->win->connection, fractal->win->win_ptr,
		fractal->img->img_ptr, 0, 0);
	fractal->last_computed_y = 0;
	fractal->last_computed_x = 0;
	fractal->op_count = 0;
}

void	render(t_fractal *fractal)
{
	int		x;
	int		y;
	int		color;

	y = fractal->last_computed_y - 1;
	while (++y < HEIGHT)
	{
		x = fractal->last_computed_x - 1;
		while (++x < WIDTH)
		{
			if (!fractal->escaped[y * WIDTH + x])
			{
				color = compute_color(fractal, x, y);
				put_pixel_to_image(fractal->img, x, y, color);
			}
			if (fractal->op_count >= MAX_OP_PER_FRAME)
			{
				stop_calc_and_render(fractal, x, y);
				return ;
			}
			fractal->last_computed_x = 0;
		}
	}
	put_image(fractal);
}
