/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:32:27 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/06 18:03:49 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"
#include "../../includes/utils.h"

static void	compute_next_elem(t_complex *z, t_complex *c)
{
	t_complex	tmp;

	tmp.re = z->re;
	tmp.im = z->im;
	z->re = ((z->re * z->re) - (z->im * z->im) + c->re);
	z->im = ((2 * tmp.re * tmp.im) + c->im);
}

static void	init_complex(t_fractal *fractal, t_complex *z,
			t_complex *c, int pixel_pos)
{
	z->re = 0;
	z->im = 0;
	c->re = fractal->pre_computed_c[pixel_pos].re;
	c->im = fractal->pre_computed_c[pixel_pos].im;
}

static int	get_color_index(t_fractal *fractal, t_complex z,
			int pixel_pos, int index)
{
	double		smooth;

	fractal->escaped[pixel_pos] = true;
	smooth = smooth_factor(z, index);
	smooth = log2(1 + smooth) / log2(fractal->max_iter);
	index = (int)(smooth * 255);
	return (index);
}

static int	compute_color(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			index;

	init_complex(fractal, &z, &c, y * WIDTH + x);
	i = 0;
	while (i < fractal->max_iter && ((z.re * z.re) + (z.im * z.im)) <= 4)
	{
		compute_next_elem(&z, &c);
		fractal->op_count += OP_PER_COMPUTE;
		i++;
	}
	if (i == fractal->max_iter)
		return (BLACK);
	index = get_color_index(fractal, z, y * WIDTH + x, i);
	if (index >= 0)
		return (fractal->pre_computed_colors[index]);
	return (fractal->pre_computed_colors[0]);
}

static void	stop_calc_and_render(t_fractal *fractal, int x, int y)
{
	fractal->last_computed_y = y;
	fractal->last_computed_x = x;
	mlx_put_image_to_window(fractal->win->connection, fractal->win->win_ptr,
		fractal->img->img_ptr, 0, 0);
	fractal->op_count = 0;
}

static void	put_image(t_fractal *fractal)
{
	int	scaled_iter;

	mlx_put_image_to_window(fractal->win->connection, fractal->win->win_ptr,
		fractal->img->img_ptr, 0, 0);
	fractal->last_computed_y = 0;
	fractal->last_computed_x = 0;
	fractal->op_count = 0;
	reset_escaped(fractal);
	scaled_iter = (int)(INCR_ITER / fractal->zoom) / 10;
	if (fractal->max_iter <= 206 + scaled_iter)
		fractal->max_iter += 10 + scaled_iter;
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
		}
		fractal->last_computed_x = 0;
	}
	put_image(fractal);
}
