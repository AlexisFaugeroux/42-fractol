/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:50:17 by alexis            #+#    #+#             */
/*   Updated: 2025/03/03 20:25:06 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define OP_PER_COMPUTE 7
# define MAX_OP_PER_FRAME 1000000

# include "fractol.h"

void	render(t_fractal *fractal);
double	smooth_factor(t_complex z, int iteration);

#endif
