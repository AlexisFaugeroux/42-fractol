/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:48:35 by alexis            #+#    #+#             */
/*   Updated: 2025/03/11 11:29:34 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "parse.h"

t_fractal	*init_fractal(t_args *args);
void		init_hooks(t_fractal *fractal);

#endif
