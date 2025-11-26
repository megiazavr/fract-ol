/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:21:09 by megiazar          #+#    #+#             */
/*   Updated: 2025/10/01 19:16:01 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	double	zoom_scale;
	double	mouse_x;
	double	mouse_y;

	zoom_scale = 1.3;
	mouse_x = (x - WIDTH / 2.0) / fractal->zoom + fractal->move_x;
	mouse_y = (HEIGHT / 2.0 - y) / fractal->zoom + fractal->move_y;
	if (button == 4)
		fractal->zoom *= zoom_scale;
	else if (button == 5)
		fractal->zoom /= zoom_scale;
	else
		return (0);
	fractal->move_x = mouse_x - (x - WIDTH / 2.0) / fractal->zoom;
	fractal->move_y = mouse_y - (HEIGHT / 2.0 - y) / fractal->zoom;
	render(fractal);
	return (0);
}

void	render(t_fractal *fractal)
{
	if (fractal->fractal_type == 0)
		draw_mandelbrot(fractal);
	else if (fractal->fractal_type == 1)
		draw_julia(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
