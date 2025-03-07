/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_theme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:30:43 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/07 17:17:44 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/theme.h"
#include "../../includes/compute.h"
#include "../../includes/utils.h"

void	init_theme(t_fractal *fractal)
{
	fractal->theme = (t_theme *)malloc(sizeof(t_theme));
	if (!fractal->theme)
		clean_and_exit_failure(fractal);
	fractal->theme->name = ft_strdup("Theme");
	set_default(fractal->theme);
	compute_colors(fractal->theme);
}
