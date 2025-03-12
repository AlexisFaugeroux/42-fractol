/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_theme_ide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:01:41 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/11 16:25:08 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	set_tokyonight(t_theme *theme)
{
	theme->current = 9;
    theme->palette[0] = 0x00171724;
    theme->palette[1] = 0x001B1D2B;
    theme->palette[2] = 0x00202234;
    theme->palette[3] = 0x004B4D66;
    theme->palette[4] = 0x00A9B1D6;
    theme->palette[5] = 0x00F7768E;
    theme->palette[6] = 0x00BB9AF7;
    theme->palette[7] = 0x00FF9E64;
    theme->palette[8] = 0x00E0AF68;
    theme->palette[9] = 0x009ECE6A;
    theme->palette[10] = 0x007AA2F7;
}

void	set_dracula(t_theme *theme)
{
	theme->current = 10;
	theme->palette[0] = 0x00f1fa8c;
	theme->palette[1] = 0x00ff5555;
	theme->palette[2] = 0x00bd93f9;
	theme->palette[3] = 0x00ff79c6;
	theme->palette[4] = 0x00ffb86c;
	theme->palette[5] = 0x0050fa7b;
	theme->palette[6] = 0x008be9fd;
	theme->palette[7] = 0x006272a4;
	theme->palette[8] = 0x00f8f8f2;
	theme->palette[9] = 0x0044475a;
	theme->palette[10] = 0x00282a36;
}
