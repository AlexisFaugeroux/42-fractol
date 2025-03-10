/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:12:39 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/09 18:41:47 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	extract_rgb(int color, unsigned char *r, unsigned char *g, unsigned char *b)
{
	*r = (color >> 16) & 0xFF;
	*g = (color >> 8) & 0xFF;
	*b = color & 0xFF;
}

int	build_color(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}
