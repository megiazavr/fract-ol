/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:52:52 by megiazar          #+#    #+#             */
/*   Updated: 2025/09/28 19:50:28 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(fractal->mlx, fractal->img.img);
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		exit(0);
	}
	else if (keycode == 65361)
		fractal->move_x -= 10 / fractal->zoom;
	else if (keycode == 65363)
		fractal->move_x += 10 / fractal->zoom;
	else if (keycode == 65362)
		fractal->move_y -= 10 / fractal->zoom;
	else if (keycode == 65364)
		fractal->move_y += 10 / fractal->zoom;
	render(fractal);
	return (0);
}
