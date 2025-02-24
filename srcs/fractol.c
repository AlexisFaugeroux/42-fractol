/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:25:58 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/24 15:20:29 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#define DEFAULT_WIDTH 1920
#define DEFAULT_HEIGHT 1080
#define ESCAPE_KEY 65307

typedef struct s_window
{
	void	*connection;
	void	*ptr;
}				t_window;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_length;
	int		endian;
}				t_image;

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * image->line_length + x * (image->bits_per_pixels / 8));
	dst = image->addr + offset;
	*(unsigned int *)dst = (unsigned int)color;
}

int	close_window(int keycode, t_window *window)
{
	if (keycode == ESCAPE_KEY)
	{
		mlx_destroy_window(window->connection, window->ptr);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_window	window;
	// t_image	image;

	window.connection = mlx_init();
	window.ptr = mlx_new_window(window.connection, DEFAULT_WIDTH, DEFAULT_HEIGHT, "Fractol");
	mlx_hook(window.ptr, 2, 1L<<0, close_window, &window);
	mlx_loop(window.connection);
	return (0);
}
