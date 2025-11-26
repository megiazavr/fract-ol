/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:53:06 by megiazar          #+#    #+#             */
/*   Updated: 2025/10/01 19:16:55 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int i, int max_iterations)
{
	int	r;
	int	g;
	int	b;

	if (i == max_iterations)
		return (0xFFFFFF);
	r = (int)(180 + 75 * sin(0.1546 * i));
	g = (int)(59 + 47 * sin(0.785 * i));
	b = (int)(0 + 30 * sin(0.0000012 * i));
	return ((r << 16) | (g << 8) | b);
}

void	mandelbrot_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	t_complex	z;
	double		tmp;
	int			i;
	int			color;

	c.x = (x - WIDTH / 2.0) / fractal->zoom + fractal->move_x;
	c.y = (HEIGHT / 2.0 - y) / fractal->zoom + fractal->move_y;
	z.x = 0;
	z.y = 0;
	i = 0;
	while (i < fractal->iterations_definition)
	{
		tmp = z.x * z.x - z.y * z.y;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp + c.x;
		if ((z.x * z.x + z.y * z.y) > fractal->escape_value)
			break ;
		i++;
	}
	color = get_color(i, fractal->iterations_definition);
	my_mlx_pixel_put(&fractal->img, x, y, color);
}

void	draw_mandelbrot(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mandelbrot_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
}
