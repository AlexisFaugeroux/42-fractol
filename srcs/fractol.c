/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:25:58 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/12 11:16:40 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/init.h"
#include "../includes/render.h"
#include "../includes/utils.h"

void	init_args(t_args *args)
{
	args->name = NULL;
	args->julia_re = 0;
	args->julia_im = 0;
	args->theme = NULL;
}

int	main(int argc, char *argv[])
{
	t_args		args;
	t_fractal	*fractal;

	init_args(&args);
	parse(&args, argc, argv);
	fractal = init_fractal(&args);
	init_hooks(fractal);
	mlx_loop_hook(fractal->win->connection, (void *)render, fractal);
	mlx_loop(fractal->win->connection);
	clean_up(fractal);
	return (0);
}
