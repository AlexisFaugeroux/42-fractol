/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:28:24 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/11 19:00:20 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	init_args(t_args *args)
{
	args->name = NULL;
	args->theme = NULL;
}

void	parse_arg(t_args *args, char *arg)
{
	if (ft_strncmp(arg, "--theme=", 8) == 0)
		parse_theme(args, arg);
}

void	parse(t_args *args, int argc, char *argv[])
{
	int		i;

	if (argc < 2)
	{
		ft_putstr_fd("Error: too few arguments\n\n", 2);
		display_params_list();
		exit(EXIT_SUCCESS);
	}
	if (argc == 2)
	{
		parse_name(args, argv[1]);
		args->theme = ft_strdup("default");
		return ;
	}
	i = 1;
	while (i < argc)
	{
		if (i == argc - 1)
			parse_name(args, argv[i]);
		else
			parse_arg(args, argv[i]);
		i++;
	}
}
