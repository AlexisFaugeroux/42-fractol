/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:10:43 by alexis            #+#    #+#             */
/*   Updated: 2025/03/13 17:35:15 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * img->line_len + x * (img->bpp / 8));
	dst = img->pixels + offset;
	*(unsigned int *)dst = (unsigned int)color;
}

void	clean_up(t_fractal *fractal)
{
	if (fractal->img)
		free(fractal->img);
	if (fractal->win)
	{
		mlx_destroy_display(fractal->win->connection);
		free(fractal->win);
	}
	if (fractal->ens_name)
		free(fractal->ens_name);
	if (fractal->theme)
	{
		free(fractal->theme->name);
		free(fractal->theme);
	}
	if (fractal->escaped)
		free(fractal->escaped);
	free(fractal);
}

void	clean_and_exit_failure(t_fractal *fractal)
{
	clean_up(fractal);
	exit(EXIT_FAILURE);
}

void	reset_escaped(t_fractal *fractal)
{
	ft_memset(fractal->escaped, false, WIDTH * HEIGHT * sizeof(bool));
}

void	reset_params(t_fractal *fractal)
{
	reset_escaped(fractal);
	fractal->max_iter = fractal->base_iter;
	fractal->last_computed_x = 0;
	fractal->last_computed_y = 0;
	fractal->op_count = 0;
}
