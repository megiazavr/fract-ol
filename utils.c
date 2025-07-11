/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:20:56 by megiazar          #+#    #+#             */
/*   Updated: 2025/07/10 15:44:10 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// to be able call fractal by CLI(Command line interface) arg
// -zoom flag usage
int ft_strncmp(char *s1, char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (n > 0 && *s1 == *s2 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}