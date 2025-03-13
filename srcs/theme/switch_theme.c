/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:27:18 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 10:18:59 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/compute.h"
#include "../../includes/utils.h"

void	switch_theme(t_fractal *fractal)
{
	if (fractal->theme->current == 10)
	{
		fractal->theme->current = 0;
		fractal->theme->
			setters[fractal->theme->current](fractal->theme);
		return ;
	}
	fractal->theme->current++;
	fractal->theme->
		setters[fractal->theme->current](fractal->theme);
	compute_colors(fractal->theme);
	reset_params(fractal);
}
