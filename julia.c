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
#include <mlx.h>

void	draw_julia(t_vars *vars)
{
	int		x, y, i;
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			color;

	// fixed c for Julia set
	// the julia constant c = a + bi is hardcoded(not passed from a command line)
	c = vars->julia_c;

	y = 0;
	while (y < 800)
	{
		y++;
		x = 0;
		while (x < 600)
		{
			x++;
			// мапим координаты пикселя в комплексную плоскость
			z.real = (x - 300) / vars->zoom + vars->move_x;
			z.imagery = (y - 400) / vars->zoom + vars->move_y;

			i = 0;
			while (i < 100)
			{
				tmp = z.real * z.real - z.imagery * z.imagery;
				z.imagery = 2 * z.real * z.imagery + c.imagery;
				z.real = tmp + c.real;
				if ((z.real * z.real + z.imagery * z.imagery) > 4)
					break ;
				i++;
			}
			int r = (i * 9) % 256;
			int g = (i * 2) % 256;
			int b = (i * 13) % 256;
			color = (r << 16) | (g << 8) | b;

			my_mlx_pixel_put(&vars->img, x, y, color);
		}
		y++;
	}
}

/* int	main(void)
{
	t_vars vars;

	vars.zoom = 250.0;
	vars.move_x = 0.0;
	vars.move_y = 0.0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Meow");
	
// bpp - bits per pixel
// creating an image
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_lenght, &vars.img.endian);
	
	draw_julia(&vars);
// put image in a window
	//my_mlx_pixel_put(&img, 5, 5, 0x050000);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
} */

/* int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data		img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Meow");
	
// bpp - bits per pixel
// creating an image
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	
	draw_julia(&vars);
// put image in a window
	my_mlx_pixel_put(&img, 5, 5, 0x050000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
} */

