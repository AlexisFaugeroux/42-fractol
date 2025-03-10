/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_theme_others.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:07:14 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/08 12:39:31 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	set_psyche(t_theme *theme)
{
	theme->palette[0] = 0x00ff00ff;
	theme->palette[1] = 0x00ff6f00;
	theme->palette[2] = 0x00ffff00;
	theme->palette[3] = 0x0000ff00;
	theme->palette[4] = 0x0000ffff;
	theme->palette[5] = 0x000000ff;
	theme->palette[6] = 0x00ff007f;
	theme->palette[7] = 0x00ff1493;
	theme->palette[8] = 0x008000ff;
	theme->palette[9] = 0x00ff4500;
	theme->palette[10] = 0x00ffffa5;
	theme->palette[11] = 0x00ff00a0;
}

void	set_autumn(t_theme *theme)
{
	theme->palette[0] = 0x002d181d;
	theme->palette[1] = 0x00503045;
	theme->palette[2] = 0x00687597;
	theme->palette[3] = 0x003c5470;
	theme->palette[4] = 0x008c93a5;
	theme->palette[5] = 0x00dfabad;
	theme->palette[6] = 0x00b78b8d;
	theme->palette[7] = 0x00a06f71;
	theme->palette[8] = 0x00edd9e3;
	theme->palette[9] = 0x00d5bfc9;
	theme->palette[10] = 0x00c0a6b1;
	theme->palette[11] = 0x00988084;
}

void	set_cyberpunk(t_theme *theme)
{
	theme->palette[0] = 0x00000000;
	theme->palette[1] = 0x00101030;
	theme->palette[2] = 0x00302080;
	theme->palette[3] = 0x006010A0;
	theme->palette[4] = 0x008030C0;
	theme->palette[5] = 0x00A000FF;
	theme->palette[6] = 0x00FF00FF;
	theme->palette[7] = 0x00FF0080;
	theme->palette[8] = 0x00FF4000;
	theme->palette[9] = 0x00FFFF00;
	theme->palette[10] = 0x00A0FF00;
	theme->palette[11] = 0x0000FF00;
}

void	set_default(t_theme *theme)
{
	theme->palette[0] = 0x00000033;
	theme->palette[1] = 0x00220066;
	theme->palette[2] = 0x00440099;
	theme->palette[3] = 0x006600CC;
	theme->palette[4] = 0x008800FF;
	theme->palette[5] = 0x00AA33FF;
	theme->palette[6] = 0x00CC66FF;
	theme->palette[7] = 0x00FF9966;
	theme->palette[8] = 0x00FF7733;
	theme->palette[9] = 0x00FFAA88;
	theme->palette[10] = 0x00FFFF99;
	theme->palette[11] = 0x00FFFFFF;
}
