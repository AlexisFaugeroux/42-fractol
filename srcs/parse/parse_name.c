/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:09:33 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 10:37:20 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	handle_unknown_name(t_args *args, char *arg)
{
	ft_putstr_fd("Error: unknown ensemble name ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\n\n", 2);
	display_params_list();
	clean_args(args);
	exit(EXIT_FAILURE);
}

void	parse_name(t_args *args, char *arg)
{
	if (ft_strcmp(arg, "mandelbrot") == 0
		|| ft_strcmp(arg, "julia") == 0
		|| ft_strcmp(arg, "burning_ship") == 0)
	{
		args->name = ft_strdup(arg);
		if (!args->name)
		{
			clean_args(args);
			exit(EXIT_FAILURE);
		}
	}
	else
		handle_unknown_name(args, arg);
}
