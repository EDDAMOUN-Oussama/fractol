/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_util_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 08:06:01 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/14 16:41:52 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	ft_change(double p, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * p / old_max + new_min);
}

double	ft_atod(char *str)
{
	double	r;
	double	s;
	double	i;

	r = ((s = 1.0), (i = 1.0), 0.0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s *= -1.0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		r = r * 10 + s * (*(str++) - '0');
	if (*str && *(str++) == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			i /= 10.0;
			r = r + s * (*str - '0') * i;
			str++;
		}
	}
	return (r);
}

void	ft_free(t_fractol *f, int c)
{
	if (f->img.img)
		mlx_destroy_image(f->mlx_coniction, f->img.img);
	if (f->mlx_window)
		mlx_destroy_window(f->mlx_coniction, f->mlx_window);
	if (f->mlx_coniction)
		free(f->mlx_coniction);
	exit(c);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

double	ft_abs(double a, char *s)
{
	if (a < 0 && !ft_strncmp("Burning Ship", s, 13))
		a = -a;
	return (a);
}
