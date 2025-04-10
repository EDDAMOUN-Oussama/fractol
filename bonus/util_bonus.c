/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 08:05:36 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/22 06:50:27 by oeddamou         ###   ########.fr       */
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
		if (f->iteration < 7)
			f->iteration += 42;
		f->iteration %= 300;
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

void	ft_print_error(void)
{
	write(2, "Invalid Argements!\nPlease write: \n", 34);
	write(2, "./fractol_bonus \"Mandelbrot\" \n Or\n", 34);
	write(2, "./fractol_bonus \"Julia\" \'x\' \'y\'\n", 32);
	write(2, "x and y are real numbers preferably between -2.0 and 2.0\n", 57);
	write(2, " Or \n./fractol_bonus \"Burning\"\n", 31);
}
