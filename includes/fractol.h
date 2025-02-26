/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:30:23 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/26 12:31:56 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define DEFAULT_WIDTH 1920
# define DEFAULT_HEIGHT 1080
# define ESCAPE_KEY 65307

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
}				t_fractal;

#endif
