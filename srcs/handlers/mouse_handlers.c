/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:49:38 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 10:25:06 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/handlers.h"
#include "../../includes/compute.h"
#include "../../includes/utils.h"

static void	handle_zoom(t_fractal *fractal, int keycode,
				double scaled_x, double scaled_y)
{
	if (keycode == 4)
	{
		reset_params(fractal);
		fractal->offset_x = scaled_x
			+ (fractal->offset_x - scaled_x) * 1.0 / ZOOM_FACTOR;
		fractal->offset_y = scaled_y
			+ (fractal->offset_y - scaled_y) * 1.0 / ZOOM_FACTOR;
		fractal->zoom *= 1.0 / ZOOM_FACTOR;
	}
	else if (keycode == 5)
	{
		reset_params(fractal);
		fractal->offset_x = scaled_x
			+ (fractal->offset_x - scaled_x) * ZOOM_FACTOR;
		fractal->offset_y = scaled_y
			+ (fractal->offset_y - scaled_y) * ZOOM_FACTOR;
		fractal->zoom *= ZOOM_FACTOR;
	}
}

int	handle_mouse_event(int keycode, int x, int y, t_fractal *fractal)
{
	double	scaled_x;
	double	scaled_y;

	scaled_x = fractal->pre_computed[y * WIDTH + x].re;
	scaled_y = fractal->pre_computed[y * WIDTH + x].im;
	handle_zoom(fractal, keycode, scaled_x, scaled_y);
	shift_colors(fractal->theme);
	pre_compute(fractal);
	return (0);
}
