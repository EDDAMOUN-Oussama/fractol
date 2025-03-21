/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 07:00:38 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/19 09:49:18 by oeddamou         ###   ########.fr       */
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

void	ft_print_error(void)
{
	write(2, "Invalid Argements!\nPlease write: \n", 35);
	write(2, "./fractol \"Mandelbrot\"\n Or\n", 27);
	write(2, "./fractol \"Julia\" \"x\" \"y\"\n", 27);
	write(2, "x and y are real numbers preferably between -2.0 and 2.0\n", 57);
}
