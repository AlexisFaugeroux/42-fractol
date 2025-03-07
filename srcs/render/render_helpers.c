/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:50:47 by alexis            #+#    #+#             */
/*   Updated: 2025/03/07 17:28:08 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

double	smooth_factor(t_complex z, int iteration)
{
	double	log_zn;
	double	nu;
	double	smooth;

	log_zn = log(z.re * z.re + z.im * z.im) / 2;
	nu = log(log_zn / log(2)) / log(2);
	smooth = iteration + 1 - nu;
	return (smooth);
}

void	init_complex(t_fractal *fractal, t_complex *z,
			t_complex *c, int pixel_pos)
{
	z->re = 0;
	z->im = 0;
	c->re = fractal->computed_c[pixel_pos].re;
	c->im = fractal->computed_c[pixel_pos].im;
}
