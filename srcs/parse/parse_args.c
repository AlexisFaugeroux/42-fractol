/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:09:33 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/12 11:11:03 by afaugero         ###   ########.fr       */
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

void	handle_unknown_theme(t_args *args, char *arg)
{
	ft_putstr_fd("Error: unknown theme ", 2);
	ft_putstr_fd(arg + 8, 2);
	ft_putstr_fd("\n\n", 2);
	display_params_list();
	clean_args(args);
	exit(EXIT_FAILURE);
}

void	parse_name(t_args *args, char *arg)
{
	if (ft_strcmp(arg, "mandelbrot") == 0
		|| ft_strcmp(arg, "julia") == 0)
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

void	parse_theme(t_args *args, char *arg)
{
	if (ft_strcmp(arg + 8, "default")
		&& ft_strcmp(arg + 8, "red")
		&& ft_strcmp(arg + 8, "blue")
		&& ft_strcmp(arg + 8, "purple")
		&& ft_strcmp(arg + 8, "black_white")
		&& ft_strcmp(arg + 8, "lava")
		&& ft_strcmp(arg + 8, "sky")
		&& ft_strcmp(arg + 8, "psyche")
		&& ft_strcmp(arg + 8, "autumn")
		&& ft_strcmp(arg + 8, "tokyonight")
		&& ft_strcmp(arg + 8, "dracula")
	)
		handle_unknown_theme(args, arg);
	else
	{
		if (args->theme)
			free(args->theme);
		args->theme = ft_strdup(arg + 8);
		if (!args->theme)
		{
			clean_args(args);
			exit(EXIT_FAILURE);
		}
	}
}
