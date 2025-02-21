/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:25:58 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/21 18:00:27 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

	offset = (y * image->line_length + x) * (image->bits_per_pixels / 8);
	dst = image->addr + offset;
	*(unsigned int *)dst = (unsigned int)color;
}

int	main(void)
{
	void	*mlx;
	t_image	image;

	mlx = mlx_init();
	image.img = mlx_new_image(mlx, 1920, 1080);
	image.addr = mlx_get_data_addr(
			image.img,
			&image.bits_per_pixels,
			&image.line_length,
			&image.endian
			);
	return (0);
}
