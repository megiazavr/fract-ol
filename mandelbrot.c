/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:53:06 by megiazar          #+#    #+#             */
/*   Updated: 2025/07/11 18:05:11 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

// bites are not aligned, line_lenght differs from the actual window width.
//we should always calculate the memory offset using the line len set by mlx_get_data_addr
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel) / 8);
	*(unsigned int*)dst = color;
}

void	draw_mandelbrot(t_data *img)
{
	int		x, y, i;
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			color;
	y = 0;
	while (y < 1080)
	{
		y++;
		x = 0;
		while (x < 1920)
		{
			x++;
			// map pixel to c
			c.real = (x - 960) / 250.0;
			c.imagery = (y - 540) / 250.0;

			// z styart at 0
			z.real = 0;
			z.imagery = 0;
			i = 0;
			while (i < 500)
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

		//	color = 0xFF0000 * i / 100;
			my_mlx_pixel_put(img, x, y, color);
		}
	}
}

int	main(void)
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
	
	draw_mandelbrot(&img);
// put image in a window
	my_mlx_pixel_put(&img, 5, 5, 0x050000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}