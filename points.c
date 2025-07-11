/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:00:52 by megiazar          #+#    #+#             */
/*   Updated: 2025/07/09 18:38:40 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"

// i use double to store floating-point numb(i.e decimal numbers)
// we need exact values and int cant give them cuz it will cut em
// float save only ~6 symbols after . (bad for zoom)
// even one number cut after . can change the value in depth of 100+ iterations 

int main(void)
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

	while (i < 100)
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

		// the mandelbrot (and july) set built by the principe "dot stay in the circle of radius of 2"
		// |z|^2 = x^2 + y^2 <= 4
		// if |z| became more than 2 (z^2 > 4) - the point fly away and we stopped
		// in this case loop is impossibe and the dote will grow in a progressive way
	
		printf("iteration n -> %d real %f imaginary%f\n", i, z.real, z.imagery);
	}
}