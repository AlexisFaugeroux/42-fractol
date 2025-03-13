/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:03:30 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 17:42:33 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static void	handle_invalid_iter(t_args *args, char *arg)
{
	ft_putstr_fd("Error: invalid iteration value ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\n\n", 2);
	display_params_list();
	clean_args(args);
	exit(EXIT_FAILURE);
}

void	parse_iter(t_args *args, char *arg)
{
	unsigned char	iter;

	iter = ft_atoi(arg + 7);
	if (iter < 30 || iter > 255)
		handle_invalid_iter(args, arg + 7);
	args->iter = iter;
}
