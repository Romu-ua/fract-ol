/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:52:38 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/04 16:52:38 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!argv || !*argv)
		return (0);
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 6)))
	{
		fractol.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 6))
		{
			fractol.julia_x = ft_atof(argv[2]);
			fractol.julia_x = ft_atof(argv[3]);
		}
		init(&fractol);
		render(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, 1);
		exit(1);
	}
	return (0);
}
