/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:10:43 by alexis            #+#    #+#             */
/*   Updated: 2025/03/06 14:24:25 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	clean_up(t_fractal *fractal)
{
	if (fractal->img)
		free(fractal->img);
	if (fractal->buffer)
		free(fractal->buffer);
	if (fractal->win)
	{
		mlx_destroy_display(fractal->win->connection);
		free(fractal->win);
	}
	free(fractal->escaped);
	free(fractal);
}

void	clean_and_exit_failure(t_fractal *fractal)
{
	clean_up(fractal);
	exit(EXIT_FAILURE);
}

void	reset_escaped(t_fractal *fractal)
{
	ft_memset(fractal->escaped, false, WIDTH * HEIGHT * sizeof(bool));
}
