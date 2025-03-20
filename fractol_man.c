/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:52:26 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/19 09:18:00 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_man.h"

void	ft_initial(t_fractol *f, int ac, char **av)
{
	f->mlx_connection = mlx_init();
	if (!f->mlx_connection)
		exit(1);
	f->mlx_window = mlx_new_window(f->mlx_connection, WIDTH, HEIGHT, av[1]);
	if (!f->mlx_window)
		exit(1);
	f->img.img = mlx_new_image(f->mlx_connection, WIDTH, HEIGHT);
	if (!f->img.img)
		ft_free(f, 1);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp,
			&f->img.line_length, &f->img.endian);
	f->zoom = 1.0;
	if (!ft_strncmp("Julia", av[1], 6))
	{
		if (ac == 3)
			f->j_y = ((f->j_x = ft_atod(av[2])), f->j_x);
		if (ac == 4)
			f->j_x = ((f->j_y = ft_atod(av[3])), ft_atod(av[2]));
		if (ac == 2)
			f->j_x = ((f->j_y = 0.53), -0.52);
	}
}

void	put_pixel(t_img *data, int x, int y, int color)
{
	int	offset;

	offset = (y * data->line_length) + (x * (data->bpp / 8));
	*(unsigned int *)(data->addr + offset) = color;
}

void	ft_handle_pixel(int i, int j, t_fractol *f)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	double		color;
	int			cont;

	z.x = ft_change(i, -2, 2, WIDTH) * f->zoom;
	z.y = ft_change(j, 2, -2, HEIGHT) * f->zoom;
	c.y = ((c.x = z.x), z.y);
	if (!ft_strncmp("Julia", f->name, 6))
		c.y = ((c.x = f->j_x), f->j_y);
	cont = 0;
	while (cont < 100)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * tmp * z.y + c.y;
		cont++;
		if (z.x * z.x + z.y * z.y > 4)
		{
			color = ft_change(cont, 0xFFFFFF, 0xA, 100);
			return (put_pixel(&f->img, i, j, color));
		}
	}
	put_pixel(&f->img, i, j, 0x0);
}

void	ft_fractol(t_fractol *f)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			ft_handle_pixel(i, j, f);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(f->mlx_connection, f->mlx_window, f->img.img, 0, 0);
	mlx_key_hook(f->mlx_window, key_hook, f);
	mlx_mouse_hook(f->mlx_window, mouse_zoom, f);
	mlx_hook(f->mlx_window, 17, 0, close_window, f);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((ac == 2 && !ft_strncmp("Mandelbrot", av[1], 11)) || (ac > 1 && ac < 5
			&& !ft_strncmp("Julia", av[1], 6) && ft_valid(ac, av)))
	{
		fractol.name = av[1];
		ft_initial(&fractol, ac, av);
		ft_fractol(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		ft_print_error();
		exit(1);
	}
}
