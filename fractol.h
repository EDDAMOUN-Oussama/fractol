#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include "libft/libft.h"

#define WIDTH 1000
#define HEIGHT 1000

typedef struct s_complex
{
    double x;
    double y;
} t_complex;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fractol
{
    void    *mlx_coniction;
    void    *mlx_window;
	t_img	img;
	char	*name;
	double	zoom;
	double	shift_x;
	double	shift_y;
	double	j_x;
	double	j_y;
	
}	t_fractol;

double ft_change(double p, double new_min, double new_max, double old_max);
int mouse_zoom(int button, int x, int y, t_fractol *f);
double ft_atod(char *str);
void ft_free(t_fractol *f, int c);
int	key_hook(int keycode, t_fractol *f);
int	close_window(t_fractol *f);
void	ft_fractol(t_fractol *f);
#endif