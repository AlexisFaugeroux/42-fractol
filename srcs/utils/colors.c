/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:54:58 by alexis            #+#    #+#             */
/*   Updated: 2025/03/03 20:01:23 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	init_palette(t_fractal *fractal)
{
	fractal->palette[0] = 0x00000033;
	fractal->palette[1] = 0x00220066;
	fractal->palette[2] = 0x00440099;
	fractal->palette[3] = 0x006600CC;
	fractal->palette[4] = 0x008800FF;
	fractal->palette[5] = 0x00AA33FF;
	fractal->palette[6] = 0x00CC66FF;
	fractal->palette[7] = 0x00FF9966;
	fractal->palette[8] = 0x00FF7733;
	fractal->palette[9] = 0x00FFAA88;
	fractal->palette[10] = 0x00FFFF99;
	fractal->palette[11] = 0x00FFFFFF;
}
