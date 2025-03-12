/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:05:09 by alexis            #+#    #+#             */
/*   Updated: 2025/03/11 17:05:00 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/handlers.h"
#include "../../includes/compute.h"
#include "../../includes/theme.h"
#include "../../includes/utils.h"

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
		fractal->offset_x -= OFFSET_FACTOR * fractal->zoom;
	}
	else if (keycode == ARROW_RIGHT_KEY)
	{
		reset_params(fractal);
		fractal->offset_x += OFFSET_FACTOR * fractal->zoom;
	}
	else if (keycode == ARROW_UP_KEY)
	{
		reset_params(fractal);
		fractal->offset_y += OFFSET_FACTOR * fractal->zoom;
	}
	else if (keycode == ARROW_DOWN_KEY)
	{
		reset_params(fractal);
		fractal->offset_y -= OFFSET_FACTOR * fractal->zoom;
	}
	compute_c(fractal);
}

int	handle_key_pressed(int keycode, t_fractal *fractal)
{
	if (keycode == ESCAPE_KEY)
		handle_escape(fractal);
	else if (keycode == T_KEY)
		switch_theme(fractal);
	else
		handle_arrows(keycode, fractal);
	return (0);
}
