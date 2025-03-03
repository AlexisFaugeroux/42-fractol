/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:53:32 by alexis            #+#    #+#             */
/*   Updated: 2025/03/03 20:17:10 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fractol.h"

void	clean_and_exit_failure(t_fractal *fractal);
void	reset_escaped(t_fractal *fractal);
void	clean_up(t_fractal *fractal);
void	init_palette(t_fractal *fractal);

#endif
