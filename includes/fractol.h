/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:30:23 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/01 15:53:03 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define ESCAPE_KEY 65307
# define GAMMA 2.2

typedef struct s_win
{
	void	*connection;
	void	*win_ptr;
}				t_win;

typedef struct s_img
{
	void	*img_ptr; // pointer to image struct
	char	*pixels; // pointer to pixels
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_fractal
{
	struct s_win	*win;
	struct s_img	*img;
	int				colors[3];
	int				max_iter;
}				t_fractal;

typedef struct s_complex
{
	double	Re;
	double	Im;
}				t_complex;

void	render(t_fractal *fractal);
void	put_pixel_to_image(t_img *img, int x, int y, int color);

#endif
