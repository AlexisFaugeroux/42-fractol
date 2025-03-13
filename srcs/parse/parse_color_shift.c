/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_shift.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:52:39 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 20:18:48 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../includes/utils.h"

static void	handle_unknown_color_shift(t_args *args, char *arg)
{
	ft_putstr_fd("Error: unknown color shift value ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\n\n", 2);
	display_params_list();
	clean_and_exit(NULL, args, EXIT_SUCCESS);
}

void	parse_color_shift(t_args *args, char *arg)
{
	if (ft_strcmp(arg + 14, "true") && ft_strcmp(arg + 14, "false"))
		handle_unknown_color_shift(args, arg);
	if (ft_strcmp(arg + 14, "true") == 0)
		args->color_shift = true;
	else if (ft_strcmp(arg + 14, "false") == 0)
		args->color_shift = false;
	else
		args->color_shift = true;
}
