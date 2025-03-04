/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:27:14 by alexis            #+#    #+#             */
/*   Updated: 2025/03/04 17:03:58 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_H
# define COMPUTE_H

#include "fractol.h"

typedef struct s_scale
{
	double	scaled_step_x;
	double	scaled_step_y;
	double	start_x;
	double	start_y;
}				t_scale;

void	pre_compute_c(t_fractal *fractal);
void	pre_compute_colors(t_fractal *fractal);

#endif
