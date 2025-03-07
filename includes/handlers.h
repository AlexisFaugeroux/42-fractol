/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:48:47 by alexis            #+#    #+#             */
/*   Updated: 2025/03/07 10:20:53 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "fractol.h"

# if OS_CODE == 2
#  define ESCAPE_KEY 53
#  define ARROW_LEFT_KEY 123
#  define ARROW_RIGHT_KEY 124
#  define ARROW_UP_KEY 126
#  define ARROW_DOWN_KEY 125
# else
#  define ESCAPE_KEY 65307
#  define ARROW_LEFT_KEY 65361
#  define ARROW_RIGHT_KEY 65363
#  define ARROW_UP_KEY 65364
#  define ARROW_DOWN_KEY 65362
# endif

# define ZOOM_FACTOR 1.1
# define OFFSET_FACTOR 0.1

int		destroy_window(t_fractal *fractal);
int		handle_key_pressed(int keycode, t_fractal *fractal);
int		handle_mouse_event(int keycode, int x, int y, t_fractal *fractal);

#endif
