/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:16:07 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/29 18:39:17 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_spaces_and_sign(const char *nptr, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

double	ft_atof(const char *nptr)
{
	int		i;
	int		sign;
	double	int_part;
	double	frac_part;
	double	div;

	i = skip_spaces_and_sign(nptr, &sign);
	int_part = (double)ft_atoi(nptr + i);
	frac_part = 0;
	div = 10;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		i++;
	if (nptr[i] == '.')
	{
		i++;
		while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		{
			frac_part += (nptr[i] - '0') / div;
			div *= 10;
			i++;
		}
	}
	return ((int_part + frac_part) * sign);
}
