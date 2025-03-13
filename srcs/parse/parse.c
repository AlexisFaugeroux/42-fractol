/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:28:24 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 15:20:52 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static void	handle_too_few_arguments(void)
{
	ft_putstr_fd("Error: too few arguments\n\n", 2);
	display_params_list();
	exit(EXIT_SUCCESS);
}

static void	handle_unknown_arg(t_args *args, char *arg)
{
	ft_putstr_fd("Error: unknown optional argument ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\n\n", 2);
	display_params_list();
	clean_args(args);
	exit(EXIT_FAILURE);
}

static void	parse_arg(t_args *args, char *arg)
{
	if (ft_strncmp(arg, "--theme=", 8) == 0)
		parse_theme(args, arg);
	else if (ft_strncmp(arg, "--smooth=", 9) == 0)
		parse_smooth(args, arg);
	else if (ft_strncmp(arg, "--color_shift=", 14) == 0)
		parse_color_shift(args, arg);
	else
		handle_unknown_arg(args, arg);
}

static void	init_parse(t_args *args)
{
	args->name = NULL;
	args->theme = NULL;
	args->smooth = true;
	args->smooth = false;
	args->julia_re = 0;
	args->julia_im = 0;
}

void	parse(t_args *args, int argc, char *argv[])
{
	int	i;

	if (argc < 2)
		handle_too_few_arguments();
	init_parse(args);
	parse_name(args, argv[1]);
	args->theme = ft_strdup("default");
	if (!args->theme)
	{
		clean_args(args);
		exit(EXIT_FAILURE);
	}
	i = 2;
	if (ft_strcmp(args->name, "julia") == 0)
	{
		args->julia_re = ft_atod(argv[2]);
		args->julia_im = ft_atod(argv[3]);
		i += 2;
	}
	while (i < argc)
	{
		parse_arg(args, argv[i]);
		i++;
	}
}
