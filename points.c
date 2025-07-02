/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:00:52 by megiazar          #+#    #+#             */
/*   Updated: 2025/07/02 21:25:36 by megiazar         ###   ########.fr       */
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

	while (i < 42)
	{
		++i;
		// using general formula to get the square of a number 
		// in the real component x^2 - y^2 
		tmp_real = (z.real * z.real) - (z.imagery * z.imagery);
		
		//for the imagery part
		z.imagery = 2 * z.real * z.imagery;
		z.real = tmp_real; //have to use that cuz in previous i shoulve use zero
		
		// adding C value
		z.real += point.real;
		z.imagery += point.imagery;

		printf("iteration n -> %d real %f imaginary%f\n", i, z.real, z.imagery);
	}
}