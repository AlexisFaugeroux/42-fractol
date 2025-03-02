/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:05:09 by alexis            #+#    #+#             */
/*   Updated: 2025/03/02 22:02:22 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	handle_key_pressed(int keycode, t_fractal *fractal)
{
	if (keycode == ESCAPE_KEY)
	{
		if (fractal->img->img_ptr)
			mlx_destroy_image(fractal->win->connection, fractal->img->img_ptr);
		mlx_destroy_window(fractal->win->connection, fractal->win->win_ptr);
		exit(0);
	}
	else if (keycode == ARROW_LEFT_KEY)
	{
		reset_escaped(fractal);
		fractal->max_iter = DEFAULT_MAX_ITER;
		fractal->offset_x -= 0.1 * fractal->zoom;
	}
	else if (keycode == ARROW_RIGHT_KEY)
	{
		reset_escaped(fractal);
		fractal->max_iter = DEFAULT_MAX_ITER;
		fractal->offset_x += 0.1 * fractal->zoom;
	}
	else if (keycode == ARROW_UP_KEY)
	{
		reset_escaped(fractal);
		fractal->max_iter = DEFAULT_MAX_ITER;
		fractal->offset_y += 0.1 * fractal->zoom;
	}
	else if (keycode == ARROW_DOWN_KEY)
	{
		reset_escaped(fractal);
		fractal->max_iter = DEFAULT_MAX_ITER;
		fractal->offset_y -= 0.1 * fractal->zoom;
	}
	return (0);
}

int	destroy_window(t_fractal *fractal)
{
	if (fractal->img->img_ptr)
		mlx_destroy_image(fractal->win->connection, fractal->img->img_ptr);
	mlx_destroy_window(fractal->win->connection, fractal->win->win_ptr);
	exit(0);
}

int	handle_mouse_event(int keycode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		reset_escaped(fractal);
		fractal->max_iter = DEFAULT_MAX_ITER;
		fractal->zoom *= 1.1;
	}
	else if (keycode == 5)
	{
		reset_escaped(fractal);
		fractal->max_iter = DEFAULT_MAX_ITER;
		fractal->zoom *= 0.9;
	}
	return (0);
}
