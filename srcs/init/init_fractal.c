/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:06:50 by alexis            #+#    #+#             */
/*   Updated: 2025/03/07 15:57:33 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init.h"
#include "../../includes/theme.h"
#include "../../includes/compute.h"
#include "../../includes/utils.h"

static void	init_params(t_fractal *fractal)
{
	fractal->max_iter = DEFAULT_MAX_ITER;
	fractal->last_computed_x = 0;
	fractal->last_computed_y = 0;
	fractal->op_count = 0;
	fractal->zoom = 1;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
}

static void	init_escaped(t_fractal *fractal)
{
	fractal->escaped = (bool *)malloc(sizeof(bool) * HEIGHT * WIDTH);
	if (!fractal->escaped)
		clean_and_exit_failure(fractal);
	reset_escaped(fractal);
}

static void	init_img(t_fractal *fractal)
{
	fractal->img = (t_img *)malloc(sizeof(t_img));
	fractal->buffer = (t_img *)malloc(sizeof(t_img));
	if (!fractal->img | !fractal->buffer)
	{
		clean_up(fractal);
		exit(EXIT_FAILURE);
	}
	fractal->img->img_ptr = mlx_new_image(fractal->win->connection,
			WIDTH, HEIGHT);
	fractal->img->pixels = mlx_get_data_addr(
			fractal->img->img_ptr,
			&(fractal->img->bpp),
			&(fractal->img->line_len),
			&(fractal->img->endian)
			);
}

static void	init_win(t_fractal *fractal)
{
	fractal->win = (t_win *)malloc(sizeof(t_win));
	if (!fractal->win)
		clean_and_exit_failure(fractal);
	fractal->win->connection = mlx_init();
	if (!fractal->win->connection)
		clean_and_exit_failure(fractal);
	fractal->win->win_ptr = mlx_new_window(fractal->win->connection,
			WIDTH, HEIGHT, "Fractol");
	if (!fractal->win->win_ptr)
		clean_and_exit_failure(fractal);
}

t_fractal	*init_fractal(void)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractal)
		exit(EXIT_FAILURE);
	init_win(fractal);
	init_img(fractal);
	init_theme(fractal);
	init_escaped(fractal);
	init_params(fractal);
	compute_c(fractal);
	return (fractal);
}
