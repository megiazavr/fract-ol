/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:05:57 by megiazar          #+#    #+#             */
/*   Updated: 2025/07/11 19:30:24 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// have 2 prompts: fractol mandelbrot or fractol julia <real;imagery>
// the main func is a TL,DR of your application

#include "fractol.h"

void	show_error_and_exit(void)
{
	write(2, ERROR_MESSAGE, sizeof(ERROR_MESSAGE));
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (!is_valid_args(argc, argv))
		show_error_and_exit();

	// базовые параметры
	vars.zoom = 400.0;
	vars.move_x = 0.0;
	vars.move_y = 0.0;

	// определить тип фрактала
	if (!strncmp(argv[1], "mandelbrot", 10))
		vars.fractal_type = 0;
	else if (!strncmp(argv[1], "julia", 5))
	{
		vars.fractal_type = 1;
		vars.julia_c.real = atof(argv[2]);
		vars.julia_c.imagery = atof(argv[3]);
	}

	// Инициализация MLX
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "fract-ol");

	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img,
			&vars.img.bits_per_pixel, &vars.img.line_lenght, &vars.img.endian);

	// Первая отрисовка
	render(&vars);

	// Хук на колёсико мышки
	mlx_mouse_hook(vars.win, mouse_hook, &vars);

	// Основной цикл
	mlx_loop(vars.mlx);

	return (0);
}
