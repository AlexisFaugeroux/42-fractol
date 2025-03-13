/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:29:57 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 20:29:59 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/init.h"
#include "../includes/render.h"
#include "../includes/utils.h"

int	main(int argc, char *argv[])
{
	t_args		args;
	t_fractal	*fractal;

	parse(&args, argc, argv);
	fractal = init_fractal(&args);
	init_hooks(fractal);
	mlx_loop_hook(fractal->win->connection, (void *)render, fractal);
	mlx_loop(fractal->win->connection);
	clean_up(fractal);
	return (0);
}
