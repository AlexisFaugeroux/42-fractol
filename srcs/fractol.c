/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:25:58 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/01 16:21:46 by alexis           ###   ########.fr       */
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

int	close_window(int keycode, t_fractal *fractal)
{
	if (keycode == ESCAPE_KEY)
	{
		if (fractal->img->img_ptr)
			mlx_destroy_image(fractal->win->connection, fractal->img->img_ptr);
		mlx_destroy_window(fractal->win->connection, fractal->win->win_ptr);
		exit(0);
	}
	return (0);
}

int	destroy_window(t_fractal *fractal)
{
	if (fractal->img->img_ptr)
		mlx_destroy_image(fractal->win->connection, fractal->img->img_ptr);
	mlx_destroy_window(fractal->win->connection, fractal->win->win_ptr);
	exit(0);
}

void	clean_up(t_fractal *fractal)
{
	if (fractal->win)
		free(fractal->win);
	if (fractal->img)
		free(fractal->img);
	mlx_destroy_display(fractal->win->connection);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->win = (t_win *)malloc(sizeof(t_win));
	fractal->img = (t_img *)malloc(sizeof(t_img));
	if (!fractal->win || !fractal->img)
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
	fractal->img->img_ptr = mlx_new_image(fractal->win->connection, WIDTH, HEIGHT);
	fractal->img->pixels = mlx_get_data_addr(
			fractal->img->img_ptr,
			&(fractal->img->bpp),
			&(fractal->img->line_len),
			&(fractal->img->endian)
			);
	fractal->colors[0] = 0x00000033;
	fractal->colors[1] = 0x00220066;
	fractal->colors[2] = 0x00440099;
	fractal->colors[3] = 0x006600CC;
	fractal->colors[4] = 0x008800FF;
	fractal->colors[5] = 0x00AA33FF;
	fractal->colors[6] = 0x00CC66FF;
	fractal->colors[7] = 0x00FF9966;
	fractal->colors[8] = 0x00FF7733;
	fractal->colors[9] = 0x00FFAA88;
	fractal->colors[10] = 0x00FFFF99;
	fractal->colors[11] = 0x00FFFFFF;
	fractal->max_iter = 256;
}

void	init_hooks(t_fractal *fractal)
{
	mlx_hook(fractal->win->win_ptr, 2, 1L << 0, close_window, fractal);
	mlx_hook(fractal->win->win_ptr, 17, 1L << 17, destroy_window, fractal);
}

int	main(void)
{
	t_fractal	fractal;

	init_fractal(&fractal);
	init_hooks(&fractal);
	render(&fractal);
	mlx_loop(fractal.win->connection);
	clean_up(&fractal);
	return (0);
}
