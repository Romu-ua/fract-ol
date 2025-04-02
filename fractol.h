/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:58:33 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/03 17:58:36 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

# define ERROR_MESSAGE "Please enter \n\t\" ./fractol mandelbrot\" or \n\t\" \
./fractol julia <x> <y>\n"
# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000
# define WHITE 0xFFFFFF

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;
typedef struct s_img
{
	void	*img_ptr;
	void	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;
typedef struct s_fractol
{
	char	*name;
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	int		iter_num;
	int		escape_value;
	double	julia_x;
	double	julia_y;
	double	shift_x;
	double	shift_y;
	double	zoom;
}	t_fractol;
typedef struct s_tmp
{
	int	x;
	int	y;
}	t_tmp;

void		init(t_fractol *fractol);
void		render(t_fractol *fractol);
int			ft_strncmp(char	*s1, char *s2, int n);
void		putstr_fd(char *s, int fd);
double		ft_atof(const char *str);
int			key_handler(int keysym, t_fractol *fractol);
int			mouse_handler(int button, int x, int y, t_fractol *fractol);
int			close_handler(t_fractol *fractol);
double		map(double unscaled, double new_min, \
	double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif
