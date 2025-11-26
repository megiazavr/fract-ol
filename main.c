/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:05:57 by megiazar          #+#    #+#             */
/*   Updated: 2025/10/01 19:08:17 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_error_and_exit(void)
{
	write(2, ERROR_MESSAGE, sizeof(ERROR_MESSAGE));
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4.0;
	fractal->iterations_definition = 100;
	fractal->zoom = 300.0;
	fractal->move_x = 0.0;
	fractal->move_y = 0.0;
}

static int	is_valid_args(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		return (1);
	if (!ft_strncmp(argv[1], "julia", 5) && argc == 4)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!is_valid_args(argc, argv))
		show_error_and_exit();
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		fractal.fractal_type = 0;
	else if (!ft_strncmp(argv[1], "julia", 5))
	{
		fractal.fractal_type = 1;
		fractal.julia_c.x = ft_atof(argv[2]);
		fractal.julia_c.y = ft_atof(argv[3]);
	}
	data_init(&fractal);
	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "fract-ol");
	fractal.img.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
	fractal.img.addr = mlx_get_data_addr(fractal.img.img,
			&fractal.img.bits_per_pixel, &fractal.img.line_lenght,
			&fractal.img.endian);
	render(&fractal);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_hook (fractal.win, 2, 1L << 0, key_hook, &fractal);
	mlx_hook(fractal.win, 17, 0, close_window, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
