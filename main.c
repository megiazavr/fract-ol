/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:00:52 by megiazar          #+#    #+#             */
/*   Updated: 2025/06/30 16:29:22 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_complex
{
	double real; // x
	double imagery; // y
}	t_complex;


int main()
{
	int	i;

	i = 0;
	// zero in the formula 
	t_complex	z;
	// c in the formula f(x) = z^2 + c;
	t_complex	point;
	double 	tmp_real;

	z.real = 0;
	z.imagery = 0;

	point.real = 5;
	point.imagery = 2;

	if (i < 42)
	{
		++i;
		
	}
}