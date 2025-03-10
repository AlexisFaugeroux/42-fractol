/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:27:14 by alexis            #+#    #+#             */
/*   Updated: 2025/03/10 16:36:37 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_H
# define COMPUTE_H

# include "fractol.h"

#define PI 3.14159265358979323846

typedef struct s_scale
{
	double	scaled_step_x;
	double	scaled_step_y;
	double	start_x;
	double	start_y;
}				t_scale;

void	compute_c(t_fractal *fractal);
void	compute_colors(t_theme *theme);
void	shift_colors(t_theme *theme);
void	compute_next_elem(t_complex *z, t_complex *c);

#endif
