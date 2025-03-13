/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:30:23 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 15:08:51 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# if defined(__linux__)
#  define OS_CODE 1
#  include "../mlx_linux/mlx.h"
# elif defined(__APPLE__) && defined(__MACH__)
#  define OS_CODE 2
#  include "../mlx_mac/mlx.h"
# else
#  define OS_CODE 0
# endif

# include "../libft/libft.h"

# include <stdio.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 900
# define BLACK 0x00000000
# define DEFAULT_MAX_ITER 100

# define PALETTE_SIZE 12
# define COLORS_SIZE 256

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

typedef struct s_theme
{
	char	*name;
	int		palette[PALETTE_SIZE];
	int		colors[COLORS_SIZE];
	int		shift;
	int		current;
	void	(*setters[11])(struct s_theme *theme);
}				t_theme;

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_fractal
{
	struct s_win		*win;
	struct s_img		*img;
	struct s_theme		*theme;
	char				*ens_name;
	int					ens_id;
	struct s_complex	pre_computed[HEIGHT * WIDTH];
	struct s_complex	julia_c;
	bool				*escaped;
	bool				smooth;
	bool				color_shift;
	int					max_iter;
	int					last_computed_x;
	int					last_computed_y;
	long				op_count;
	double				zoom;
	double				offset_x;
	double				offset_y;
}				t_fractal;

#endif
