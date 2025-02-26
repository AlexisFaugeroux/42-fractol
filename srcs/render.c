/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <afaugero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:36:06 by alexis            #+#    #+#             */
/*   Updated: 2025/02/26 14:36:06 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double interpolate(double x, double x0, double y0, double x1, double y1)
{
	if (y0 == x0)
		return (0);
    return (x1 + (y1 - x1) * (x - x0) / (y0 - x0));
}

void    square_complex(double *a, double *b)
{
    *a = (*a * *a) - (*b * *b);
    *b = 2 * *b;
}

double  modulo(double za, double zb, double ca, double cb)
{
    double x;
    double y;

    x = (za * za) - (zb * zb) + ca;
    y = (2 * za * zb) + cb;
    return (sqrt((x * x) + (y * y)));
}

int compute(t_fractal *fractal, int x, int y)
{
    t_complex   z;
    t_complex   c;
    int         color;
    int         k;

    z.Re = 0;
    z.Im = 0;
    c.Re = interpolate(x, 0, WIDTH, -2, 2);
    c.Im = interpolate(y, 0, HEIGHT, -2, 2);

    color = 0XFFFFFFFF;
    k = 0;
    while (k < fractal->max_iter)
    {
        ft_printf("%lf\n", modulo(z.Re, z.Im, c.Re, c.Im));
        if (modulo(z.Re, z.Im, c.Re, c.Im) > 2)
        {
            color = 0X00000000;
            break ;
        }
        square_complex(&(z.Re), &(z.Im));
        k++;
    }
    return (color);
}

void    render(t_fractal *fractal)
{
    int x;
    int y;
    int color;

    y = 0;
    while (y < 5)
    {
        x = 0;
        while (x < 5)
        {
            color = compute(fractal, x, y);
            put_pixel_to_image(fractal->img, x, y, color);
            x++;
        }
        y++;
    }
	mlx_put_image_to_window(
        fractal->win->connection,
        fractal->win->win_ptr,
        fractal->img->img_ptr,
        0,
        0
    );
}