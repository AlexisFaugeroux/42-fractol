/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_smooth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:40:04 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 20:20:55 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../includes/utils.h"

static void	handle_unknown_smooth(t_args *args, char *arg)
{
	ft_putstr_fd("Error: unknown smooth value ", 2);
	ft_putstr_fd(arg + 9, 2);
	ft_putstr_fd("\n\n", 2);
	display_params_list();
	clean_and_exit(NULL, args, EXIT_SUCCESS);
}

void	parse_smooth(t_args *args, char *arg)
{
	if (ft_strcmp(arg + 9, "true") && ft_strcmp(arg + 9, "false"))
		handle_unknown_smooth(args, arg);
	if (ft_strcmp(arg + 9, "true") == 0)
		args->smooth = true;
	else if (ft_strcmp(arg + 9, "false") == 0)
		args->smooth = false;
	else
		args->smooth = true;
}
