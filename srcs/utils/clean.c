/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:59:36 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 21:01:41 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.././includes/parse.h"
#include "../.././includes/utils.h"

void	clean_args(t_args *args)
{
	if (args->name)
		free(args->name);
	if (args->theme)
		free(args->theme);
}

void	clean_up(t_fractal *fractal)
{
	if (fractal->img)
	{
		if (fractal->img->img_ptr)
			mlx_destroy_image(fractal->win->connection, fractal->img->img_ptr);
		free(fractal->img);
	}
	if (fractal->win)
	{
		mlx_destroy_window(fractal->win->connection, fractal->win->win_ptr);
		mlx_destroy_display(fractal->win->connection);
		free(fractal->win->connection);
		free(fractal->win);
	}
	if (fractal->ens_name)
		free(fractal->ens_name);
	if (fractal->theme)
	{
		free(fractal->theme->name);
		free(fractal->theme);
	}
	if (fractal->escaped)
		free(fractal->escaped);
	free(fractal);
}

void	clean_and_exit(t_fractal *fractal, t_args *args, int status)
{
	if (args)
		clean_args(args);
	if (fractal)
		clean_up(fractal);
	exit(status);
}

