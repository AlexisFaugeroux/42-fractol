/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:36:26 by alexis            #+#    #+#             */
/*   Updated: 2025/03/03 12:24:35 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/handlers.h"

void	init_hooks(t_fractal *fractal)
{
	mlx_hook(fractal->win->win_ptr, 2, 1L << 0, handle_key_pressed, fractal);
	mlx_hook(fractal->win->win_ptr, 17, 1L << 17, destroy_window, fractal);
	mlx_mouse_hook(fractal->win->win_ptr, handle_mouse_event, fractal);
}
