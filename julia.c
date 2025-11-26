/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:38:50 by megiazar          #+#    #+#             */
/*   Updated: 2025/07/11 19:13:25 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_julia_color(int i, int max_iterations)
{
	int	r;
	int	g;
	int	b;

	if (i == max_iterations)
		return (0x000000);
	r = (int)(128 + 53 * sin(0.1212 * i));
	g = (int)(90 + 127 * sin(0.15 * i));
	b = (int)(128 + 127 * sin(0.2 * i));
	return ((r << 16) | (g << 8) | b);
}

void	julia_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;
	int			color;

	c = fractal->julia_c;
	z.x = (x - WIDTH / 2.0) / fractal->zoom + fractal->move_x;
	z.y = (HEIGHT / 2.0 - y) / fractal->zoom + fractal->move_y;
	i = 0;
	while (i < fractal->iterations_definition)
	{
		tmp = z.x * z.x - z.y * z.y;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp + c.x;
		if ((z.x * z.x + z.y * z.y) > 4.0)
			break ;
		i++;
	}
	color = get_julia_color(i, fractal->iterations_definition);
	my_mlx_pixel_put(&fractal->img, x, y, color);
}

void	draw_julia(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			julia_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
}
