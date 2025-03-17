/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 07:00:38 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/15 13:25:21 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_man.h"

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
	x = y;
	if (button == 4)
		f->zoom *= 1.1;
	else if (button == 5)
		f->zoom *= 0.9;
	ft_fractol(f);
	return (0);
}
