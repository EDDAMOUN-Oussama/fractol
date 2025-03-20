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
						|| av[2][i] > 13) && av[2][i] != '.' 
						&& av[2][i] != ' ') || c > 1)
				return (0);
			i++;
		}
	}
	if (ac == 4)
		return (ft_valid(ac - 1, &av[1]));
	return (1);
}

void	ft_print_error(void)
{
	write(2, "Invalid Argements!\nPlease write: \n", 35);
	write(2, "./fractol Mandelbrot\n Or\n", 26);
	write(2, "./fractol Julia <double> <double>\n", 35);
}
