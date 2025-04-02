/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:51:20 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/04 16:51:21 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char	*s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && !*s1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s)
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

static int	ft_strlen(const char *c)
{
	int	len;

	len = 0;
	while (*c++)
		len++;
	return (len);
}

static int	ft_atoi(const char *c)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	while ((c[i] >= '\t' && c[i] <= '\r') || c[i] == ' ')
		c++;
	if (c[i] == '-')
		sign = -1;
	if (c[i] == '+' || c[i] == '-')
		c++;
	while (c[i] >= '0' && c[i] <= '9')
	{
		num = num * 10 + (c[i] - '0');
		c++;
		if (num * sign > 2147483647)
			return (-1);
		else if (num * sign < -2147483648)
			return (-1);
	}
	return (num * sign);
}

double	ft_atof(const char *str)
{
	double	integer;
	double	decimal;
	char	*c;
	int		len;

	c = (char *)str;
	integer = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	decimal = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		decimal /= 10;
	if (integer < 0)
		return (integer - decimal);
	else
		return (integer + decimal);
}
