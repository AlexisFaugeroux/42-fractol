/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ensemble_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:47:56 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 17:49:47 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../includes/utils.h"

void	init_ensemble_params(t_fractal *fractal, t_args *args)
{
	fractal->ens_name = ft_strdup(args->name);
	if (!fractal->ens_name)
	{
		clean_args(args);
		clean_and_exit_failure(fractal);
	}
	if (ft_strcmp(fractal->ens_name, "mandelbrot") == 0)
		fractal->ens_id = 0;
	else if (ft_strcmp(fractal->ens_name, "julia") == 0)
	{
		fractal->ens_id = 1;
		fractal->julia_c.re = args->julia_re;
		fractal->julia_c.im = args->julia_im;
	}
	else if (ft_strcmp(fractal->ens_name, "burning_ship") == 0)
		fractal->ens_id = 2;
}
