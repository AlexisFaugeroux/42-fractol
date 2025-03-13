/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_theme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:30:43 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 20:15:26 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/theme.h"
#include "../../includes/compute.h"
#include "../../includes/utils.h"

static void	init_setters(t_theme *theme)
{
	theme->setters[0] = set_default;
	theme->setters[1] = set_red;
	theme->setters[2] = set_blue;
	theme->setters[3] = set_purple;
	theme->setters[4] = set_black_white;
	theme->setters[5] = set_lava;
	theme->setters[6] = set_sky;
	theme->setters[7] = set_psyche;
	theme->setters[8] = set_autumn;
	theme->setters[9] = set_tokyonight;
	theme->setters[10] = set_dracula;
}

static void	set_theme(t_theme *theme)
{
	if (ft_strcmp(theme->name, "default") == 0)
		set_default(theme);
	else if (ft_strcmp(theme->name, "red") == 0)
		set_red(theme);
	else if (ft_strcmp(theme->name, "blue") == 0)
		set_blue(theme);
	else if (ft_strcmp(theme->name, "purple") == 0)
		set_purple(theme);
	else if (ft_strcmp(theme->name, "black_white") == 0)
		set_black_white(theme);
	else if (ft_strcmp(theme->name, "lava") == 0)
		set_lava(theme);
	else if (ft_strcmp(theme->name, "sky") == 0)
		set_sky(theme);
	else if (ft_strcmp(theme->name, "psyche") == 0)
		set_psyche(theme);
	else if (ft_strcmp(theme->name, "autumn") == 0)
		set_autumn(theme);
	else if (ft_strcmp(theme->name, "tokyonight") == 0)
		set_tokyonight(theme);
	else if (ft_strcmp(theme->name, "dracula") == 0)
		set_dracula(theme);
	else
		set_default(theme);
}

void	init_theme(t_fractal *fractal, t_args *args)
{
	fractal->theme = (t_theme *)malloc(sizeof(t_theme));
	if (!fractal->theme)
		clean_and_exit(fractal, NULL, EXIT_FAILURE);
	fractal->theme->name = ft_strdup(args->theme);
	if (!fractal->theme->name)
		clean_and_exit(fractal, args, EXIT_FAILURE);
	fractal->theme->shift = 0;
	set_theme(fractal->theme);
	init_setters(fractal->theme);
	compute_colors(fractal->theme);
}
