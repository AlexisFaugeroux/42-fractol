/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:05:09 by alexis            #+#    #+#             */
/*   Updated: 2025/03/04 17:53:38 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/handlers.h"
#include "../../includes/compute.h"
#include "../../includes/utils.h"

void	reset_params(t_fractal *fractal)
{
	reset_escaped(fractal);
	fractal->max_iter = DEFAULT_MAX_ITER;
	fractal->last_computed_x = 0;
	fractal->last_computed_y = 0;
	fractal->op_count = 0;
}


void	handle_escape(t_fractal *fractal)
{
	if (fractal->img->img_ptr)
		mlx_destroy_image(fractal->win->connection, fractal->img->img_ptr);
	mlx_destroy_window(fractal->win->connection, fractal->win->win_ptr);
	clean_up(fractal);
	exit(EXIT_SUCCESS);
}

void	handle_arrows(int keycode, t_fractal *fractal)
{
	if (keycode == ARROW_LEFT_KEY)
	{
		reset_params(fractal);
		fractal->offset_x -= 0.1 * fractal->zoom;
	}
	else if (keycode == ARROW_RIGHT_KEY)
	{
		reset_params(fractal);
		fractal->offset_x += 0.1 * fractal->zoom;
	}
	else if (keycode == ARROW_UP_KEY)
	{
		reset_params(fractal);
		fractal->offset_y += 0.1 * fractal->zoom;
	}
	else if (keycode == ARROW_DOWN_KEY)
	{
		reset_params(fractal);
		fractal->offset_y -= 0.1 * fractal->zoom;
	}
	pre_compute_c(fractal);
}

int	handle_key_pressed(int keycode, t_fractal *fractal)
{
	if (keycode == ESCAPE_KEY)
		handle_escape(fractal);
	else
		handle_arrows(keycode, fractal);
	return (0);
}

int	handle_mouse_event(int keycode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		reset_params(fractal);
		fractal->zoom *= 1.1;
	}
	else if (keycode == 5)
	{
		reset_params(fractal);
		fractal->zoom *= 0.9;
	}
	pre_compute_c(fractal);
	return (0);
}
