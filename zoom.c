/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:21:09 by megiazar          #+#    #+#             */
/*   Updated: 2025/07/14 14:44:22 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	double zoom_factor = 1.1;
	double mouse_x = (x - 960) / vars->zoom + vars->move_x;
	double mouse_y = (y - 540) / vars->zoom + vars->move_y;

	if (button == 4) // wheel up
		vars->zoom *= zoom_factor;
	if (button == 5) // wheel down
		vars->zoom /= zoom_factor;

	// zoom to the center of mouce
	vars->move_x = mouse_x - (x - 960) / vars->zoom;
	vars->move_y = mouse_y - (y - 540) / vars->zoom;

	render(vars);
	return (0);
}

void	render(t_vars *vars)
{
	if (vars->fractal_type == 0)
		draw_mandelbrot(vars);
	else if (vars->fractal_type == 1)
		draw_julia(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}