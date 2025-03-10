/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:53:32 by alexis            #+#    #+#             */
/*   Updated: 2025/03/09 18:18:25 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fractol.h"

void	put_pixel_to_image(t_img *img, int x, int y, int color);
void	clean_and_exit_failure(t_fractal *fractal);
void	reset_escaped(t_fractal *fractal);
void	clean_up(t_fractal *fractal);

void	extract_rgb(int color, unsigned char *r, unsigned char *g, unsigned char *b);
int		build_color(unsigned char r, unsigned char g, unsigned char b);

#endif
