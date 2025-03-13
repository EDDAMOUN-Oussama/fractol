/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 08:05:36 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/13 10:34:19 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == 53)
		ft_free(f, 0);
	else if (keycode == 123)
		f->shift_x += 0.5;
	else if (keycode == 124)
		f->shift_x -= 0.5;
	else if (keycode == 125)
		f->shift_y += 0.5;
	else if (keycode == 126)
		f->shift_y -= 0.5;
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

	mouse_x = (ft_change(x, -2, 2, WIDTH) + f->shift_x) * f->zoom;
	mouse_y = (ft_change(y, 2, -2, HEIGHT) + f->shift_y) * f->zoom;
	if (button == 4)
		f->zoom *= 1.1;
	if (button == 5)
		f->zoom *= 0.9;
	new_mouse_x = ft_change(x, -2, 2, WIDTH) * f->zoom + f->shift_x;
	new_mouse_y = ft_change(y, 2, -2, HEIGHT) * f->zoom + f->shift_y;
	f->shift_x += mouse_x - new_mouse_x;
	f->shift_y += mouse_y - new_mouse_y;
	ft_fractol(f);
	return (0);
}
