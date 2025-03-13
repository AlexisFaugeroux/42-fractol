/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:32:27 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 10:09:40 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"
#include "../../includes/compute.h"
#include "../../includes/utils.h"

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

static int	get_color(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			index;

	init_complex(fractal, &z, &c, y * WIDTH + x);
	i = 0;
	while (i < fractal->max_iter && ((z.re * z.re) + (z.im * z.im)) <= 4)
	{
		compute_next_elem(fractal->ens_id, &z, &c);
		fractal->op_count += OP_PER_COMPUTE;
		i++;
	}
	if (i == fractal->max_iter)
		return (BLACK);
	index = get_color_index(fractal, z, y * WIDTH + x, i);
	if (index >= 0)
		return (fractal->theme->colors[index]);
	return (fractal->theme->colors[0]);
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
	double	scaled_iter;

	mlx_put_image_to_window(fractal->win->connection, fractal->win->win_ptr,
		fractal->img->img_ptr, 0, 0);
	fractal->last_computed_y = 0;
	fractal->last_computed_x = 0;
	fractal->op_count = 0;
	scaled_iter = BASE_ITER * pow(1.0 / fractal->zoom, EXPONENT);
	if (fractal->max_iter < scaled_iter)
		fractal->max_iter = (int)(fractal->max_iter * 0.9 + scaled_iter * 0.1);
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
				color = get_color(fractal, x, y);
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
