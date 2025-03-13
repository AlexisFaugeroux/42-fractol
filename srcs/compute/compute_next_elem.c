/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_next_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:25:54 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/13 10:13:47 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	compute_next_elem(int ens_id, t_complex *z, t_complex *c)
{
	t_complex	tmp;

	tmp.re = z->re;
	tmp.im = z->im;
	if (ens_id == 2)
	{
		z->re = fabs((z->re * z->re) - (z->im * z->im) + c->re);
		z->im = fabs(((2 * tmp.re * tmp.im) + c->im));
	}
	else
	{
		z->re = (z->re * z->re) - (z->im * z->im) + c->re;
		z->im = (2 * tmp.re * tmp.im) + c->im;
	}
}
