/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 07:00:38 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/13 09:34:46 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == 53)
		ft_free(f, 0);
	return (0);
}

int	close_window(t_fractol *f)
{
	ft_free(f, 0);
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_fractol *f)
{
	double	zoom_factor;

	zoom_factor = 1.1;
	x = y;
	if (button == 1)
		f->zoom *= zoom_factor;
	else if (button == 2)
		f->zoom /= zoom_factor;
	ft_fractol(f);
	return (0);
}
