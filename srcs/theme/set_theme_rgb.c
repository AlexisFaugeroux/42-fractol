/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_theme_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:04:01 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/07 17:04:49 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/fractol.h"

void	set_red(t_theme *theme)
{
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

void	set_green(t_theme *theme)
{
	theme->palette[0] = 0x00051000;
	theme->palette[1] = 0x00082000;
	theme->palette[2] = 0x00103500;
	theme->palette[3] = 0x00185000;
	theme->palette[4] = 0x00257000;
	theme->palette[5] = 0x00359000;
	theme->palette[6] = 0x0050b000;
	theme->palette[7] = 0x0070d000;
	theme->palette[8] = 0x0090f000;
	theme->palette[9] = 0x00a5ff55;
	theme->palette[10] = 0x00c0ff75;
	theme->palette[11] = 0x00e0ff99;
}

void	set_black_white(t_theme *theme)
{
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
