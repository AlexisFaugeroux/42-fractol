/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:21:30 by alexis            #+#    #+#             */
/*   Updated: 2025/03/13 20:27:18 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/compute.h"
#include "../../includes/utils.h"

/*
 * 	Compute params needed to get coordinates of a pixel,
 * 	from [0, WIDTH] scale to the mandlebrot scale.
 *	4.0 / (double)WIDTH --> get the equivalent of a step between two pixels
 *	in the [0, WIDTH] scale to the [-2, 2] mandlebrot scale,
 *	then adjust to the zoom factor.
 *	scale->start_x --> get the position of the first pixel in the mandlebrot scale
 */
static t_scale	*new_scale(t_fractal *fractal)
{
	t_scale	*scale;

	scale = (t_scale *)malloc(sizeof(t_scale));
	if (!scale)
		clean_and_exit(fractal, NULL, EXIT_FAILURE);
	scale->scaled_step_x = 4.0 / (double)WIDTH * fractal->zoom;
	scale->scaled_step_y = 4.0 / (double)HEIGHT * fractal->zoom;
	scale->start_x = -2.0 * fractal->zoom + fractal->offset_x;
	scale->start_y = -2.0 * fractal->zoom + fractal->offset_y;
	return (scale);
}

/*
 *	For each pixel, get its value in the mandlebrot scale
 *	scale->start_y + scale->scaled_step_y * y
 *	--> get position of current pixel in mandlebrot scale
 */
void	pre_compute(t_fractal *fractal)
{
	int			x;
	int			y;
	double		im;
	t_scale		*scale;

	scale = new_scale(fractal);
	y = 0;
	while (y < HEIGHT)
	{
		im = scale->start_y + scale->scaled_step_y * y;
		x = 0;
		while (x < WIDTH)
		{
			fractal->pre_computed[y * WIDTH + x].re = scale->start_x
				+ scale->scaled_step_x * x;
			fractal->pre_computed[y * WIDTH + x].im = im;
			x++;
		}
		y++;
	}
	free(scale);
}
