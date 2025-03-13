/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_theme_basic_colors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:04:01 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 10:20:26 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/fractol.h"

void	set_red(t_theme *theme)
{
	theme->current = 1;
	theme->palette[0] = 0x00050005;
	theme->palette[1] = 0x00100008;
	theme->palette[2] = 0x00200010;
	theme->palette[3] = 0x00350018;
	theme->palette[4] = 0x00500025;
	theme->palette[5] = 0x00700035;
	theme->palette[6] = 0x00950050;
	theme->palette[7] = 0x00b50070;
	theme->palette[8] = 0x00d50090;
	theme->palette[9] = 0x00f570a5;
	theme->palette[10] = 0x00ff90c0;
	theme->palette[11] = 0x00ffb0e0;
}

void	set_blue(t_theme *theme)
{
	theme->current = 2;
	theme->palette[0] = 0x00000510;
	theme->palette[1] = 0x00000820;
	theme->palette[2] = 0x00001035;
	theme->palette[3] = 0x00001850;
	theme->palette[4] = 0x00002570;
	theme->palette[5] = 0x00003590;
	theme->palette[6] = 0x000050b0;
	theme->palette[7] = 0x000070d0;
	theme->palette[8] = 0x000090f0;
	theme->palette[9] = 0x0055a5ff;
	theme->palette[10] = 0x0075c0ff;
	theme->palette[11] = 0x0099e0ff;
}

void	set_purple(t_theme *theme)
{
	theme->current = 3;
	theme->palette[0] = 0x0083a1f3;
	theme->palette[1] = 0x005c61c5;
	theme->palette[2] = 0x00443d93;
	theme->palette[3] = 0x00737ff0;
	theme->palette[4] = 0x00342c7b;
	theme->palette[5] = 0x00a7e9fb;
	theme->palette[6] = 0x008c8af0;
	theme->palette[7] = 0x00676edf;
	theme->palette[8] = 0x009fc4fb;
	theme->palette[9] = 0x005c54ae;
	theme->palette[10] = 0x001f1153;
	theme->palette[11] = 0x00649ccc;
}

void	set_black_white(t_theme *theme)
{
	theme->current = 4;
	theme->palette[0] = 0x00000000;
	theme->palette[1] = 0x00101010;
	theme->palette[2] = 0x00202020;
	theme->palette[3] = 0x00303030;
	theme->palette[4] = 0x00454545;
	theme->palette[5] = 0x00606060;
	theme->palette[6] = 0x00757575;
	theme->palette[7] = 0x00909090;
	theme->palette[8] = 0x00AFAFAF;
	theme->palette[9] = 0x00C8C8C8;
	theme->palette[10] = 0x00E0E0E0;
	theme->palette[11] = 0x00FFFFFF;
}
