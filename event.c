/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:13:11 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/04 13:13:12 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handler(fractol);
	else if (keysym == XK_Left)
		fractol->shift_x += 0.5;
	else if (keysym == XK_Right)
		fractol->shift_x -= 0.5;
	else if (keysym == XK_Up)
		fractol->shift_y -= 0.5;
	else if (keysym == XK_Down)
		fractol->shift_y += 0.5;
	render(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	double	x_old;
	double	y_old;
	double	x_new;
	double	y_new;

	x_old = (map(x, -2, 2, WIDTH) * fractol->zoom) + fractol->shift_x;
	y_old = (map(y, 2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	if (button == Button5)
		fractol->zoom *= 0.95;
	else if (button == Button4)
		fractol->zoom *= 1.05;
	else if (button == Button1 && !ft_strncmp(fractol->name, "julia", 6))
	{
		fractol->julia_x = (map(x, -2, 2, WIDTH) * fractol->zoom) + \
		fractol->shift_x;
		fractol->julia_y = (map(y, 2, -2, HEIGHT) * fractol->zoom) + \
		fractol->shift_y;
	}
	x_new = (map(x, -2, 2, WIDTH) * fractol->zoom) + fractol->shift_x;
	y_new = (map(y, 2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	fractol->shift_x += x_old - x_new;
	fractol->shift_y += y_old - y_new;
	render(fractol);
	return (0);
}

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	return (1);
}
