/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:20:29 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/12 16:57:23 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THEME_H
# define THEME_H

# include "parse.h"

void	switch_theme(t_fractal *fractal);

void	set_default(t_theme *theme);

void	set_tokyonight(t_theme *theme);
void	set_dracula(t_theme *theme);

void	set_lava(t_theme *theme);
void	set_ice(t_theme *theme);
void	set_sky(t_theme *theme);

void	set_red(t_theme *theme);
void	set_blue(t_theme *theme);
void	set_green(t_theme *theme);
void	set_purple(t_theme *theme);
void	set_black_white(t_theme *theme);

void	set_cyberpunk(t_theme *theme);
void	set_psyche(t_theme *theme);
void	set_autumn(t_theme *theme);

#endif
