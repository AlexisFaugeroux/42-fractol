/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:28:07 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 15:00:46 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "fractol.h"

typedef struct s_args
{
	char	*name;
	char	*theme;
	bool	smooth;
	bool	color_shift;
	double	julia_re;
	double	julia_im;
}				t_args;

void	parse(t_args *args, int argc, char *argv[]);
void	parse_name(t_args *args, char *arg);
void	parse_theme(t_args *args, char *arg);
void	parse_smooth(t_args *args, char *arg);
void	parse_color_shift(t_args *args, char *arg);
void	display_params_list(void);
void	clean_args(t_args *args);

#endif
