/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:28:07 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/12 11:16:05 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_args
{
	char	*name;
	double	julia_re;
	double	julia_im;
	char	*theme;
}				t_args;

void	parse(t_args *args, int argc, char *argv[]);
void	parse_name(t_args *args, char *arg);
void	parse_theme(t_args *args, char *arg);
void	display_params_list(void);
void	clean_args(t_args *args);
