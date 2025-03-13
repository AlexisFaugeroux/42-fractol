/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:29:43 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/12 15:04:39 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	get_integer(double *res, const char *nptr, int *i)
{
	while (nptr[*i] && ft_isdigit(nptr[*i]))
	{
		*res = *res * 10.0 + nptr[*i] - '0';
		(*i)++;
	}
}

static void	get_decimal(double *res, const char *nptr, int *i)
{
	double	divisor;

	if (nptr[*i] == '.')
	{
		(*i)++;
		divisor = 10.0;
		while (nptr[*i] && ft_isdigit(nptr[*i]))
		{
			*res += (nptr[*i] - '0') / divisor ;
			divisor *= 10.0;
			(*i)++;
		}
	}
}

double	ft_atod(char const *nptr)
{
	int		i;
	int		sign;
	double	res;

	sign = 1;
	res = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	get_integer(&res, nptr, &i);
	get_decimal(&res, nptr, &i);
	return ((double)(res * sign));
}
