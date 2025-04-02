/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:50:23 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/04 16:50:24 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iter_num = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

static void	event_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_win,
		KeyPress,
		KeyPressMask,
		key_handler,
		fractol);
	mlx_hook(fractol->mlx_win,
		ButtonPress,
		ButtonPressMask,
		mouse_handler,
		fractol);
	mlx_hook(fractol->mlx_win,
		DestroyNotify,
		StructureNotifyMask,
		close_handler,
		fractol);
}

void	init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		malloc_error();
	fractol->mlx_win = mlx_new_window(fractol->mlx,
			WIDTH, HEIGHT, fractol->name);
	if (fractol->mlx_win == NULL)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx,
			WIDTH, HEIGHT);
	if (fractol->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx, fractol->mlx_win);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		malloc_error();
	}
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&(fractol->img.bpp), &(fractol->img.line_len),
			&(fractol->img.endian));
	event_init(fractol);
	data_init(fractol);
}
