/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:30:23 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/03 22:56:08 by alexis           ###   ########.fr       */
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
# define BLACK 0x00000000
# define GAMMA 2.2
# define DEFAULT_MAX_ITER 56

typedef struct s_win
{
	void	*connection;
	void	*win_ptr;
}				t_win;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_complex
{
	double	Re;
	double	Im;
}				t_complex;

typedef struct s_fractal
{
	struct s_win		*win;
	struct s_img		*img;
	struct s_img		*buffer;
	struct s_complex	pre_computed_c[HEIGHT][WIDTH];
	bool				*escaped;
	int					palette[12];
	int					pre_computed_colors[1024];
	int					max_iter;
	int					last_computed_x;
	int					last_computed_y;
	long				op_count;
	double				zoom;
	double				offset_x;
	double				offset_y;
}				t_fractal;

void	put_pixel_to_image(t_img *img, int x, int y, int color);

// compute
void	pre_compute_c(t_fractal *fractal);
void	pre_compute_colors(t_fractal *fractal);

#endif
