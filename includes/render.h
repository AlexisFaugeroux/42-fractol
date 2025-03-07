/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:50:17 by alexis            #+#    #+#             */
/*   Updated: 2025/03/07 17:28:22 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define OP_PER_COMPUTE 7
# define MAX_OP_PER_FRAME 10000000
# define INCR_ITER 1.01

# include "fractol.h"

void	render(t_fractal *fractal);
double	smooth_factor(t_complex z, int iteration);
void	init_complex(t_fractal *fractal, t_complex *z,
			t_complex *c, int pixel_pos);

#endif
