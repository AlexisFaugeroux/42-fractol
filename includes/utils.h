/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:53:32 by alexis            #+#    #+#             */
/*   Updated: 2025/03/13 20:26:52 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "parse.h"

void	display_params_list(void);
void	put_pixel_to_image(t_img *img, int x, int y, int color);
void	clean_and_exit(t_fractal *fractal, t_args *args, int status);
void	clean_args(t_args *args);
void	clean_up(t_fractal *fractal);
void	reset_escaped(t_fractal *fractal);
void	reset_params(t_fractal *fractal);

#endif
