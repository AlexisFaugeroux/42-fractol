/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:30:23 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/02 13:53:55 by alexis           ###   ########.fr       */
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
# define ARROW_LEFT_KEY 65361
# define ARROW_RIGHT_KEY 65363
# define ARROW_UP_KEY 65364
# define ARROW_DOWN_KEY 65362
# define BLACK 0x00000000
# define GAMMA 2.2

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
	int					palette[12];
	int					pre_computed_colors[1024];
	int					max_iter;
	double				zoom;
	double				offset_x;
	double				offset_y;
}				t_fractal;

void	render(t_fractal *fractal);
void	put_pixel_to_image(t_img *img, int x, int y, int color);
// handlers
int	destroy_window(t_fractal *fractal);
int	handle_key_pressed(int keycode, t_fractal *fractal);
int	handle_mouse_event(int keycode, int x, int y, t_fractal *fractal);
// compute
void	pre_compute_c(t_fractal *fractal);
void	pre_compute_colors(t_fractal *fractal);

#endif
