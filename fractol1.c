/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 08:00:37 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/07 21:51:39 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_initial(t_fractol *f, int ac, char **av)
{
	f->mlx_coniction = mlx_init();
	f->mlx_window = mlx_new_window(f->mlx_coniction, WIDTH, HEIGHT, av[1]);
	f->img.img = mlx_new_image(f->mlx_coniction, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp,
			&f->img.line_length, &f->img.endian);
    f->zoom = 1.0;
    f->shift_x = 0.0;
    f->shift_y = 0.0;
}

void put_pixel(t_img *data, int x, int y, int color)
{
    int offset;

    offset = (y * data->line_length) + (x * (data->bpp / 8));
    *(unsigned int *)(data->addr + offset) = color;
}

void ft_handle_pixel(int i, int j, t_fractol *f)
{
    t_complex z;
    t_complex c;
    double  tmp;
    double  color;
    int cont;

    z.x = ft_change(i, -2, 2, WIDTH) * f->zoom;
    z.y = ft_change(j, -2, 2, HEIGHT) * f->zoom;
    c.x = z.x;
    c.y = z.y;
    if (!ft_strncmp("Julia", f->name, 6))
    {
        c.x =  -0.835;
        c.y =  0.2321;
    }
    cont = 0;
    while (cont < 42)
    {
        tmp = z.x;
        z.x = z.x * z.x - z.y * z.y + c.x;
        z.y = 2 * tmp * z.y + c.y;
        cont++;
        if (z.x * z.x + z.y * z.y > 4)
        {
            // color = ft_change(cont, 0x0, 0xFFFFFF, 42) * f->zoom;
            color = ft_change(cont, 0x0, 0xFFFFFF, 42);
            // if (cont == 42)
            //     color = 0x000033; // أزرق غامق جدًا للخلفية
            // else
            // {
            //     double t = (double)cont / 42.0;
            //     int r = (int)(9 * (1 - t) * t * t * t * 255);
            //     int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
            //     int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
            //     color = (r << 16) | (g << 8) | b;
            // }
            put_pixel(&f->img, i, j, color);
            return ;
        }
    }
    put_pixel(&f->img, i, j, 0x0);
}
// void  ft_mandelbrot(t_fractol *f)
// {
//     int i;
//     int j;

//     i = 0;
//     while (i < WIDTH)
//     {
//         j = 0;
//         while (j < HEIGHT)
//         {
//             ft_handle_pixel(i, j, f);
//             j++;
//         }
//         i++;
//     }
//     mlx_put_image_to_window(f->mlx_coniction, f->mlx_window, f->img.img, 0, 0);
// }
int key_hook(int keycode)
{
    if (keycode == 53)
        exit(0);
    return (0);
}

int close_window(void *param)
{
    exit(0);
    return (0);
}


void ft_fractol(t_fractol *f)
{
    // if (!ft_strncmp("Mandelbrot", f->name , 11))
    // {
    //     ft_mandelbrot(f);
    // }
    // if (ft_strncmp("Julia", f->name, 6))
    // {
    //     ft_julia(f);
    // }
    int i;
    int j;

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
    mlx_put_image_to_window(f->mlx_coniction, f->mlx_window, f->img.img, 0, 0);
    mlx_key_hook(f->mlx_window, key_hook, f);
    mlx_mouse_hook(f->mlx_window, mouse_zoom, f);
    mlx_hook(f->mlx_window, 17, 0, close_window, f);
}

int mouse_zoom(int button, int x, int y, t_fractol *f)
{
    double zoom_factor;

    zoom_factor = 1.1;
    printf("%d\n", button);
    if (button == 4)
        f->zoom *= zoom_factor;
    else if (button == 5)
        f->zoom /= zoom_factor;
    ft_fractol(f);
    return (0);
}


int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((ac == 2 && !ft_strncmp("Mandelbrot", av[1], 11)) || (ac > 1 && ac < 5
			&& !ft_strncmp("Julia", av[1], 6)))
	{
		fractol.name = av[1];
        ft_initial(&fractol, ac, av);
		ft_fractol(&fractol);
		mlx_loop(fractol.mlx_coniction);
	}
	else
	{
		write(2, "Invalid Argements!\nPlease write: \n", 35);
		write(2, "./fractol Mandelbrot\n Or\n", 26);
		write(2, "./fractol Julia <double> <double>\n", 35);
		exit(1);
	}
}

