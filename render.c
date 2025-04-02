/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:14:20 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/04 13:14:21 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot_julia_init(t_complex	*z, t_complex *c,
	t_fractol *fractol, t_tmp xy)
{
	if (!ft_strncmp(fractol->name, "julia", 6))
	{
		z->x = map(xy.x, -2, 2, WIDTH) * fractol->zoom + fractol->shift_x;
		z->y = map(xy.y, 2, -2, HEIGHT) * fractol->zoom + fractol->shift_y;
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		z->x = 0.0;
		z->y = 0.0;
		c->x = map(xy.x, -2, 2, WIDTH) * fractol->zoom + fractol->shift_x;
		c->y = map(xy.y, 2, -2, HEIGHT) * fractol->zoom + fractol->shift_y;
	}
}

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	t_tmp		xy;
	int			i;
	int			color;

	xy.x = x;
	xy.y = y;
	mandelbrot_julia_init(&z, &c, fractol, xy);
	i = 0;
	while (i < fractol->iter_num)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = map(i, BLACK, WHITE, fractol->iter_num);
			my_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractol->img, WHITE);
}

void	render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win,
		fractol->img.img_ptr, 0, 0);
	return ;
}
