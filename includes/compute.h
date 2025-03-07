/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:27:14 by alexis            #+#    #+#             */
/*   Updated: 2025/03/07 17:26:47 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_H
# define COMPUTE_H

# include "fractol.h"

typedef struct s_scale
{
	double	scaled_step_x;
	double	scaled_step_y;
	double	start_x;
	double	start_y;
}				t_scale;

void	compute_c(t_fractal *fractal);
void	compute_colors(t_theme *theme);
void	compute_next_elem(t_complex *z, t_complex *c);

#endif
