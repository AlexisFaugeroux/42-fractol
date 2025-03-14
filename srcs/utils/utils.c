/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:10:43 by alexis            #+#    #+#             */
/*   Updated: 2025/03/14 09:53:53 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	display_params_list(void)
{
	ft_putstr_fd("Usage:\t./fractol [options ...] <ensemble_name>\n",
		1);
	ft_putstr_fd("\tAvailable ensemble: mandelbrot, julia, burning_ship\n\n", 1);
	ft_putstr_fd("Options:\n", 1);
	ft_putstr_fd("\t--theme=<theme_name>\t", 1);
	ft_putstr_fd("The color theme used to display the ensemble:\n\t\t\t\t", 1);
	ft_putstr_fd("default, red, blue, purple, black_white, lava,", 1);
	ft_putstr_fd(" sky, psyche, autumn, tokyonight, dracula\n\n", 1);
	ft_putstr_fd("\t--iter=<value>\t\t", 1);
	ft_putstr_fd("Set the base number of iterations ", 1);
	ft_putstr_fd("to check for divergence\n\t\t\t\t", 1);
	ft_putstr_fd("Values range from 30 to 255. Defaults to 100.\n\n", 1);
	ft_putstr_fd("\t--smooth=<value>\t", 1);
	ft_putstr_fd("Smooth colors transition\n\t\t\t\t", 1);
	ft_putstr_fd("Can be set to 'true' or 'false'. Defaults to 'true'.\n\n", 1);
	ft_putstr_fd("\t--color_shift=<value>\t", 1);
	ft_putstr_fd("Colors change over zoom/dezoom\n\t\t\t\t", 1);
	ft_putstr_fd("Can be set to 'true' or 'false'. Defaults to 'false'.\n\n", 1);
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * img->line_len + x * (img->bpp / 8));
	dst = img->pixels + offset;
	*(unsigned int *)dst = (unsigned int)color;
}

void	reset_escaped(t_fractal *fractal)
{
	ft_memset(fractal->escaped, false, WIDTH * HEIGHT * sizeof(bool));
}

void	reset_params(t_fractal *fractal)
{
	reset_escaped(fractal);
	fractal->last_computed_x = 0;
	fractal->last_computed_y = 0;
	fractal->op_count = 0;
}
