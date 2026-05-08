/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:41:25 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 20:58:58 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// Window
# define WIDTH 950
# define HEIGHT 950

// View
# define IM_MAX 2.0
# define RE_MAX 2.0
# define IM_MIN -2.0
# define RE_MIN -2.0
# define MAX_ITER 40

// Fractol types
# define JULIA 0
# define MANDELBROT_2 1
# define MANDELBROT_3 2

// Usage
# define USAGE_0 "Usage: ./fractol mandelbrot_2\n"
# define USAGE_1 "       ./fractol mandelbrot_3\n"
# define USAGE_2 "       ./fractol julia [re im]\n"

// Defines from /usr/include/X11/X.h
# define ON_EXPOSE 12
# define ON_MOUSEMOVE 6
# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define ON_MOUSEDOWN 4

// X11 event masks
# define KEY_PRESS_MASK 1L
# define BUTTON_PRESS_MASK 4L
# define POINTER_MOTION_MASK 64L
# define EXPOSURE_MASK 32768L

// Defines from /usr/include/X11/keysymdef.h
# define UP 0xff52
# define ESC 0xff1b
# define DOWN 0xff54
# define LEFT 0xff51
# define PLUS 0x003d
# define MINUS 0x002d
# define RIGHT 0xff53
# define SPACE 0x0020

// Includes
# include <math.h>
# include <fcntl.h>
# include <float.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

// Structures
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_img
{
	int		endian;
	void	*img_ptr;
	char	*img_addr;
	int		size_line;
	int		bits_per_pixel;
}	t_img;

typedef struct s_is_in
{
	t_bool	b;
	int		i;
}	t_is_in;

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	t_img		img;
	double		zoom;
	int			type;
	t_complex	julia;
	double		im_max;
	double		im_min;
	double		re_max;
	double		re_min;
	void		*mlx_ptr;
	void		*win_ptr;
	int			max_iter;
	double		color_shift;
}	t_fractol;

// Functions
int			str_len(char *str);
void		write_str(char *str);
t_complex	complex_square(t_complex a);
double		complex_abs2(t_complex a);
t_bool		parse_double(char *str, double *result);
t_bool		int_array_contains(int x, int *array);
void		fit_view_to_window(t_fractol *fractol);
t_bool		str_equal(char *str_1, char *str_2);
t_complex	complex_add(t_complex a, t_complex b);
void		init_view(t_fractol *fractol);
int			close_event(t_fractol *fractol);
int			expose_event(t_fractol *fractol);
void		render_fractal(t_fractol *fractol);
void		setup_hooks(t_fractol *fractol);
t_complex	complex_mul(t_complex a, t_complex b);
void		init_fractol(t_fractol *fractol);
void		init_graphics(t_fractol *fractol);
t_complex	pixel_to_complex(t_pixel pixel, t_fractol *fractol);
int			key_event(int keycode, t_fractol *fractol);
t_pixel		complex_to_pixel(t_complex c, t_fractol *fractol);
void		shift_event(int keycode, t_fractol *fractol);
t_is_in		is_in_mandelbrot_2(t_complex x, int max_iter);
t_is_in		is_in_mandelbrot_3(t_complex x, int max_iter);
void		image_put_pixel(t_img *img, t_pixel pixel, int color);
t_is_in		is_in_julia(t_complex x, t_complex c, int max_iter);
void		exit_cleanly(char *str, int status, t_fractol *fractol);
int			zoom_event(int button, int x, int y, t_fractol *fractol);
int			mouse_move_event(int x, int y, t_fractol *fractol);

#endif
