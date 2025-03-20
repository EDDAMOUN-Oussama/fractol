/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 08:05:36 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/19 09:51:15 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == 53)
		ft_free(f, 0);
	else if (keycode == 123)
		f->shift_x += (0.5 * f->zoom);
	else if (keycode == 124)
		f->shift_x -= (0.5 * f->zoom);
	else if (keycode == 125)
		f->shift_y -= (0.5 * f->zoom);
	else if (keycode == 126)
		f->shift_y += (0.5 * f->zoom);
	else
	{
		if (keycode == 69)
			f->iteration += 5;
		else if (keycode == 78)
			f->iteration -= 5;
		if (f->iteration < 0)
			f->iteration += 42;
		f->iteration %= 250;
	}
	ft_fractol(f);
	return (0);
}

int	close_window(t_fractol *f)
{
	ft_free(f, 0);
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_fractol *f)
{
	double	mouse_x;
	double	mouse_y;
	double	new_mouse_x;
	double	new_mouse_y;

	mouse_x = ft_change(x, -2, 2, WIDTH) * f->zoom + f->shift_x;
	mouse_y = ft_change(y, -2, 2, HEIGHT) * f->zoom + f->shift_y;
	if (!ft_strncmp("Julia", f->name, 6))
		mouse_y = ft_change(y, 2, -2, HEIGHT) * f->zoom + f->shift_y;
	if (button == 4)
		f->zoom *= 1.1;
	if (button == 5)
		f->zoom *= 0.9;
	new_mouse_x = ft_change(x, -2, 2, WIDTH) * f->zoom + f->shift_x;
	new_mouse_y = ft_change(y, -2, 2, HEIGHT) * f->zoom + f->shift_y;
	if (!ft_strncmp("Julia", f->name, 6))
		new_mouse_y = ft_change(y, 2, -2, HEIGHT) * f->zoom + f->shift_y;
	f->shift_x += mouse_x - new_mouse_x;
	f->shift_y += mouse_y - new_mouse_y;
	ft_fractol(f);
	return (0);
}

void	put_pixel(t_img *data, int x, int y, int color)
{
	int	offset;

	offset = (y * data->line_length) + (x * (data->bpp / 8));
	*(unsigned int *)(data->addr + offset) = color;
}

int	ft_valid(int ac, char **av)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (ac == 2)
		return (1);
	if (ac > 2)
	{
		while (av[2][i])
		{
			if (av[2][i] == '.')
				c++;
			if (((av[2][i] < '0' || av[2][i] > '9') && (av[2][i] < 9
						|| av[2][i] > 13) && av[2][i] != '.' && av[2][i] != ' ')
				|| c > 1)
				return (0);
			i++;
		}
	}
	if (ac == 4)
		return (ft_valid(ac - 1, &av[1]));
	return (1);
}
