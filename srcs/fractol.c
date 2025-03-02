/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:25:58 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/02 22:00:01 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
	if (fractal->buffer)
		free(fractal->buffer);
	if (fractal->win)
	{
		mlx_destroy_display(fractal->win->connection);
		free(fractal->win);
	}
	free(fractal->escaped);
	free(fractal);
}

void	init_imgs(t_fractal *fractal)
{
	fractal->img = (t_img *)malloc(sizeof(t_img));
	fractal->buffer = (t_img *)malloc(sizeof(t_img));
	if (!fractal->img | !fractal->buffer)
	{
		clean_up(fractal);
		exit(EXIT_FAILURE);
	}
	fractal->img->img_ptr = mlx_new_image(fractal->win->connection, WIDTH, HEIGHT);
	fractal->img->pixels = mlx_get_data_addr(
			fractal->img->img_ptr,
			&(fractal->img->bpp),
			&(fractal->img->line_len),
			&(fractal->img->endian)
			);
	fractal->buffer->img_ptr = mlx_new_image(fractal->win->connection, WIDTH, HEIGHT);
	fractal->buffer->pixels = mlx_get_data_addr(
			fractal->buffer->img_ptr,
			&(fractal->buffer->bpp),
			&(fractal->buffer->line_len),
			&(fractal->buffer->endian)
			);
}

void	reset_escaped(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractal->escaped[y * WIDTH + x] = false;
			x++;
		}
		y++;
	}
}

void	init_escaped(t_fractal * fractal)
{
	fractal->escaped = (bool *)malloc(sizeof(bool) * HEIGHT * WIDTH);
	if (!fractal->escaped)
	{
		clean_up(fractal);
		exit(EXIT_FAILURE);
	}
	reset_escaped(fractal);
}

t_fractal	*init_fractal()
{
	t_fractal *fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractal)
		exit(EXIT_FAILURE);
	fractal->win = (t_win *)malloc(sizeof(t_win));
	if (!fractal->win)
	{
		clean_up(fractal);
		exit(EXIT_FAILURE);
	}
	fractal->win->connection = mlx_init();
	if (!fractal->win->connection)
	{
		clean_up(fractal);
		exit(EXIT_FAILURE);
	}
	fractal->win->win_ptr = mlx_new_window(
			fractal->win->connection,
			WIDTH, HEIGHT,
			"Fractol");
	if (!fractal->win->win_ptr)
	{
		clean_up(fractal);
		exit(EXIT_FAILURE);
	}
	init_imgs(fractal);
	fractal->palette[0] = 0x00000033;
	fractal->palette[1] = 0x00220066;
	fractal->palette[2] = 0x00440099;
	fractal->palette[3] = 0x006600CC;
	fractal->palette[4] = 0x008800FF;
	fractal->palette[5] = 0x00AA33FF;
	fractal->palette[6] = 0x00CC66FF;
	fractal->palette[7] = 0x00FF9966;
	fractal->palette[8] = 0x00FF7733;
	fractal->palette[9] = 0x00FFAA88;
	fractal->palette[10] = 0x00FFFF99;
	fractal->palette[11] = 0x00FFFFFF;
	fractal->max_iter = DEFAULT_MAX_ITER;
	fractal->last_computed_x = 0;
	fractal->last_computed_y = 0;
	fractal->op_count = 0;
	fractal->zoom = 1;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	init_escaped(fractal);
	return (fractal);
}

void	init_hooks(t_fractal *fractal)
{
	mlx_hook(fractal->win->win_ptr, 2, 1L << 0, handle_key_pressed, fractal);
	mlx_hook(fractal->win->win_ptr, 17, 1L << 17, destroy_window, fractal);
	mlx_mouse_hook(fractal->win->win_ptr, handle_mouse_event, fractal);
}

int	main(void)
{
	t_fractal	*fractal;

	fractal = init_fractal();
	init_hooks(fractal);
	pre_compute_colors(fractal);
	pre_compute_c(fractal);
	mlx_loop_hook(fractal->win->connection, (void *)render, fractal);
	mlx_loop(fractal->win->connection);
	clean_up(fractal);
	return (0);
}
