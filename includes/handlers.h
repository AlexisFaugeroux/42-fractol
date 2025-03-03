/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:48:47 by alexis            #+#    #+#             */
/*   Updated: 2025/03/03 11:52:54 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# define ESCAPE_KEY 65307
# define ARROW_LEFT_KEY 65361
# define ARROW_RIGHT_KEY 65363
# define ARROW_UP_KEY 65364
# define ARROW_DOWN_KEY 65362

# include "fractol.h"

int		destroy_window(t_fractal *fractal);
int		handle_key_pressed(int keycode, t_fractal *fractal);
int		handle_mouse_event(int keycode, int x, int y, t_fractal *fractal);

#endif
