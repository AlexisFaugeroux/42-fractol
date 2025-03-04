/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:25:58 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/04 17:58:00 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/init.h"
#include "../includes/render.h"
#include "../includes/utils.h"

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * img->line_len + x * (img->bpp / 8));
	dst = img->pixels + offset;
	*(unsigned int *)dst = (unsigned int)color;
}

int	main(void)
{
	t_fractal	*fractal;

	fractal = init_fractal();
	init_hooks(fractal);
	mlx_loop_hook(fractal->win->connection, (void *)render, fractal);
	mlx_loop(fractal->win->connection);
	clean_up(fractal);
	return (0);
}
