/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:27:14 by alexis            #+#    #+#             */
/*   Updated: 2025/03/13 10:09:21 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_H
# define COMPUTE_H

# include "fractol.h"

# define PI 3.14159265358979323846

typedef struct s_scale
{
	double	scaled_step_x;
	double	scaled_step_y;
	double	start_x;
	double	start_y;
}				t_scale;

void	pre_compute(t_fractal *fractal);
void	compute_colors(t_theme *theme);
void	shift_colors(t_theme *theme);
void	compute_next_elem(int ens_id, t_complex *z, t_complex *c);

#endif
