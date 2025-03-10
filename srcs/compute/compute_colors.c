/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:22:59 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/10 17:24:17 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/compute.h"

static int	interpolate_color(double t, int color_1, int color_2)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

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
		scaled = t * (PALETTE_SIZE - 1);
		index_low = (int)scaled;
		t_corrected = scaled - index_low;
		theme->colors[i] = interpolate_color(
				t_corrected,
				theme->palette[index_low],
				theme->palette[(index_low + 1) % PALETTE_SIZE]);
		i++;
	}
}

static double	get_shift_factor(double shift_factor)
{
	static double	sign = 1.0;

	if (sign < 0 && shift_factor < 0.0)
		sign = 1.0;
	else if (sign > 0 && shift_factor > 1.0)
		sign = -1.0;
	return (shift_factor + (0.01 * sign));
}

void	shift_colors(t_theme *theme)
{
	int				i;
	int				index_low;
	static double	shift_factor;
	double			t;
	double			t_corrected;

	shift_factor = get_shift_factor(shift_factor);
	i = 0;
	while (i < COLORS_SIZE)
	{
		t = ((double)i / COLORS_SIZE + shift_factor);
		t = fmod(t, 1.0);
		index_low = (int)(t * (PALETTE_SIZE - 1));
		t_corrected = t * (PALETTE_SIZE - 1) - index_low;
		theme->colors[i] = interpolate_color(
			t_corrected,
			theme->palette[index_low],
			theme->palette[(index_low + 1) % PALETTE_SIZE]);
		i++;
	}
}
