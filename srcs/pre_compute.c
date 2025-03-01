/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:21:30 by alexis            #+#    #+#             */
/*   Updated: 2025/03/01 21:48:08 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	interpolate(double x, double x0, double x1, double y0, double y1)
{
	if (x1 == x0)
		return (0);
	return (y0 + (x - x0) * ((y1 - y0) / (x1 - x0)));
}

void	pre_compute(t_fractal *fractal)
{
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractal->pre_computed[y][x].Re = interpolate(x, 0, WIDTH, -2, 2);
			fractal->pre_computed[y][x].Im = interpolate(y, 0, HEIGHT, -2, 2);
			x++;
		}
		y++;
	}
}
