/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 08:05:36 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/10 13:49:07 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == 53)
		ft_free(f, 0);
    else if (keycode == 123)
        f->shift_x += 0.5;
    else if (keycode ==124)
        f->shift_x -= 0.5;
    else if (keycode == 125)
        f->shift_y -= 0.5;
    else if (keycode == 126)
        f->shift_y += 0.5;
    ft_fractol(f);
	return (0);
}

int	close_window(t_fractol *f)
{
	ft_free(f, 0);
	return (0);
}
#include <stdio.h>
// int	mouse_zoom(int button, int x, int y, t_fractol *f)
// {
// 	double	zoom_factor;
//     double  mouse_x;
//     double  mouse_y;
//     mouse_x = ft_change(x - WIDTH / 2, -2, 2, WIDTH) * f->zoom;
//     mouse_y = ft_change(y - HEIGHT / 2, -2, 2, HEIGHT) * f->zoom;
// 	zoom_factor = 1.1;
// 	if (button == 1)
//         {
//             f->zoom /= zoom_factor;
//             f->shift_x  += mouse_x;
//             f->shift_y  +=  mouse_y;
//         }
// 	else if (button == 2)
//     {
//         f->zoom *= zoom_factor;
//         f->shift_x  -= mouse_x;
//         f->shift_y  -=  mouse_y;
//     }

// 	ft_fractol(f);
// 	return (0);
// }

int	mouse_zoom(int button, int x, int y, t_fractol *f)
{
	double	real;
	double	imag;
    printf("before ++++++++> x = %d , y = %d , x_sh : %f y_sh : %f \n", x , y , f->shift_x , f->shift_y);

    
	real = ft_abs((ft_change(x, -2, 2, WIDTH)) * f->zoom + f->shift_x, f->name);
	imag = ft_abs((ft_change(y, -2, 2, WIDTH)) * f->zoom + f->shift_y, f->name);
    if (button == 1)
	f->zoom *= 1.1;
    if (button == 2)
	f->zoom /= 1.1;
	f->shift_x = real - ft_abs((ft_change(x, -2, 2, WIDTH)) * f->zoom + f->shift_x, f->name);
	f->shift_y = imag - ft_abs((ft_change(y, -2, 2, WIDTH)) * f->zoom + f->shift_y, f->name);
    // printf("after +++++++++++>   x = %d , y = %d , x_sh : %f y_sh : %f \n", x , y , f->shift_x , f->shift_y);
	ft_fractol(f);
    return (0);
}


