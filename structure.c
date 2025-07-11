/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:20:21 by megiazar          #+#    #+#             */
/*   Updated: 2025/07/11 19:20:59 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_args(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		return (1);
	if (!ft_strncmp(argv[1], "julia", 5) && argc == 4)
		return (1);
	return (0);
}
