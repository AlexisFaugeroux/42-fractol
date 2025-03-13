/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:05:09 by alexis            #+#    #+#             */
/*   Updated: 2025/03/13 20:12:37 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/handlers.h"
#include "../../includes/compute.h"
#include "../../includes/theme.h"
#include "../../includes/utils.h"

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
	pre_compute(fractal);
}

int	handle_key_pressed(int keycode, t_fractal *fractal)
{
	if (keycode == ESCAPE_KEY)
		clean_and_exit(fractal, NULL, EXIT_SUCCESS);
	else if (keycode == T_KEY)
		switch_theme(fractal);
	else
		handle_arrows(keycode, fractal);
	return (0);
}
