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

# include <stdio.h>
# include <stdlib.h> 
# include <unistd.h>
# include <math.h>
# include "lib/minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Bro enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1;value2>\"\n"

typedef struct s_complex
{
	double real; // x
	double imagery; // y
}	t_complex;

// to open the window i use the command
// cc window.c ./lib/minilibx-linux/libmlx.a -I ./lib/minilibx-linux -lXext -lX11 -lm
typedef struct s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;
}	t_data;

typedef struct s_vars {
	t_data img;
	double zoom;
	double move_x;
	double move_y;
} t_vars;

void	render(t_vars *vars);
int	mouse_hook(int button, int x, int y, t_vars *vars);

#endif