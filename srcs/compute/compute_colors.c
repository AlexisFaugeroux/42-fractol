/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:22:59 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/07 17:24:36 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	interpolate_color(double t, int color_1, int color_2)
{
	int	r;
	int	g;
	int	b;

	r = (1 - t) * ((color_1 >> 16 & 0xFF)) + t * ((color_2 >> 16) & 0xFF);
	g = (1 - t) * ((color_1 >> 8 & 0xFF)) + t * ((color_2 >> 8) & 0xFF);
	b = (1 - t) * (color_1 & 0xFF) + t * (color_2 & 0xFF);
	return (r << 16 | g << 8 | b);
}

void	compute_colors(t_theme *theme)
{
	int		i;
	int		index_low;
	double	scaled;
	double	t;
	double	t_corrected;

	i = 0;
	while (i < 256)
	{
		t = (double)i / 255;
		scaled = t * (12 - 1);
		index_low = (int)scaled;
		t_corrected = scaled - index_low;
		theme->colors[i] = interpolate_color(
				t_corrected,
				theme->palette[index_low],
				theme->palette[index_low + 1]);
		i++;
	}
}
