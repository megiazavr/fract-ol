/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:26:58 by megiazar          #+#    #+#             */
/*   Updated: 2025/07/02 21:24:38 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define ERROR_MESSAGE "OOPS! Please, gimme the name & 2 args if its juliaset"
# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		endian;
	int		line_lenght;
	int		bits_per_pixel;
}	t_data;

typedef struct fractal
{
	t_data		img;
	void		*mlx;
	void		*win;
	double		zoom;
	double		move_x;
	double		move_y;
	int			fractal_type;
	int			iterations_definition;
	double		escape_value;
	t_complex	julia_c;
}	t_fractal;

int		key_hook(int keycode, t_fractal *fractal);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
int		close_window(t_fractal *fractal);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	render(t_fractal *fractal);
void	draw_mandelbrot(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);
void	data_init(t_fractal *fractal);

#endif
