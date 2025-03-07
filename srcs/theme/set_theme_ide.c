/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_theme_ide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:01:41 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/07 17:08:16 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	set_tokyonight(t_theme *theme)
{
	theme->palette[0] = 0x00292e42;
	theme->palette[1] = 0x00394b70;
	theme->palette[2] = 0x007dcfff;
	theme->palette[3] = 0x00b4f9f8;
	theme->palette[4] = 0x00bb9af7;
	theme->palette[5] = 0x009d7cd8;
	theme->palette[6] = 0x00ff9e64;
	theme->palette[7] = 0x00ffc777;
	theme->palette[8] = 0x00c3e88d;
	theme->palette[9] = 0x00c53b53;
	theme->palette[10] = 0x0041a6b5;
	theme->palette[11] = 0x00ff757f;
}

void	set_dracula(t_theme *theme)
{
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

void	set_catppuccin(t_theme *theme)
{
	theme->palette[0] = 0x001d1e28;
	theme->palette[1] = 0x00262836;
	theme->palette[2] = 0x00414155;
	theme->palette[3] = 0x00b4befe;
	theme->palette[4] = 0x0084aaff;
	theme->palette[5] = 0x0080ffea;
	theme->palette[6] = 0x00a6da95;
	theme->palette[7] = 0x00f5a97f;
	theme->palette[8] = 0x00eba0ac;
	theme->palette[9] = 0x00f28fad;
	theme->palette[10] = 0x00c6a0f6;
	theme->palette[11] = 0x00f2cdcd;
}
