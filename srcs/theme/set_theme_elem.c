/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_theme_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:05:48 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/07 17:06:29 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	set_lava(t_theme *theme)
{
	theme->palette[0] = 0x00200000;
	theme->palette[1] = 0x00400000;
	theme->palette[2] = 0x00800000;
	theme->palette[3] = 0x00C00000;
	theme->palette[4] = 0x00FF4000;
	theme->palette[5] = 0x00FF8000;
	theme->palette[6] = 0x00FFA000;
	theme->palette[7] = 0x00FFC000;
	theme->palette[8] = 0x00FFD040;
	theme->palette[9] = 0x00FFE060;
	theme->palette[10] = 0x00FFF080;
	theme->palette[11] = 0x00FFFFA0;
}

void	set_ice(t_theme *theme)
{
	theme->palette[0] = 0x00001020;
	theme->palette[1] = 0x00002040;
	theme->palette[2] = 0x00004080;
	theme->palette[3] = 0x000060A0;
	theme->palette[4] = 0x000080C0;
	theme->palette[5] = 0x0020A0E0;
	theme->palette[6] = 0x0040C0F0;
	theme->palette[7] = 0x0060D0FF;
	theme->palette[8] = 0x0080E0FF;
	theme->palette[9] = 0x00A0F0FF;
	theme->palette[10] = 0x00C0FFFF;
	theme->palette[11] = 0x00FFFFFF;
}

void	set_space(t_theme *theme)
{
	theme->palette[0] = 0x00000020;
	theme->palette[1] = 0x00002040;
	theme->palette[2] = 0x00204080;
	theme->palette[3] = 0x004060A0;
	theme->palette[4] = 0x006080C0;
	theme->palette[5] = 0x0080A0E0;
	theme->palette[6] = 0x00A0C0FF;
	theme->palette[7] = 0x00D4AF37;
	theme->palette[8] = 0x00FFD700;
	theme->palette[9] = 0x00FFBF00;
	theme->palette[10] = 0x00E060FF;
	theme->palette[11] = 0x00FF2080;
}
