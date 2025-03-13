/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_theme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:35:18 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 20:21:38 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../includes/utils.h"

static void	handle_unknown_theme(t_args *args, char *arg)
{
	ft_putstr_fd("Error: unknown theme ", 2);
	ft_putstr_fd(arg + 8, 2);
	ft_putstr_fd("\n\n", 2);
	display_params_list();
	clean_and_exit(NULL, args, EXIT_SUCCESS);
}

void	parse_theme(t_args *args, char *arg)
{
	if (ft_strcmp(arg + 8, "default") == 0
		|| ft_strcmp(arg + 8, "red") == 0
		|| ft_strcmp(arg + 8, "blue") == 0
		|| ft_strcmp(arg + 8, "purple") == 0
		|| ft_strcmp(arg + 8, "black_white") == 0
		|| ft_strcmp(arg + 8, "lava") == 0
		|| ft_strcmp(arg + 8, "sky") == 0
		|| ft_strcmp(arg + 8, "psyche") == 0
		|| ft_strcmp(arg + 8, "autumn") == 0
		|| ft_strcmp(arg + 8, "tokyonight") == 0
		|| ft_strcmp(arg + 8, "dracula") == 0
	)
	{
		if (args->theme)
			free(args->theme);
		args->theme = ft_strdup(arg + 8);
		if (!args->theme)
			clean_and_exit(NULL, args, EXIT_FAILURE);
	}
	else
		handle_unknown_theme(args, arg);
}
