/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_next_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:25:54 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/07 17:26:28 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	compute_next_elem(t_complex *z, t_complex *c)
{
	t_complex	tmp;

	tmp.re = z->re;
	tmp.im = z->im;
	z->re = ((z->re * z->re) - (z->im * z->im) + c->re);
	z->im = ((2 * tmp.re * tmp.im) + c->im);
}
