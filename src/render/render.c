/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:33:35 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 21:02:57 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	blue_color(int iter, int max_iter, double shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	t = fmod((double)iter / max_iter + shift, 1.0);
	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	b = (int)(pow(t, 0.5) * 255);
	return ((r << 16) | (g << 8) | b);
}

static void	color_pixel(t_pixel pixel, t_fractol *fractol)
{
	t_complex	m;
	t_is_in		is_in;

	m = pixel_to_complex(pixel, fractol);
	if (fractol->type == JULIA)
		is_in = is_in_julia(m, fractol->julia, fractol->max_iter);
	else if (fractol->type == MANDELBROT_2)
		is_in = is_in_mandelbrot_2(m, fractol->max_iter);
	else
		is_in = is_in_mandelbrot_3(m, fractol->max_iter);
	if (is_in.b == TRUE)
		image_put_pixel(&fractol->img, pixel, 0x000000);
	else
		image_put_pixel(
			&fractol->img, pixel,
			blue_color(is_in.i, fractol->max_iter, fractol->color_shift));
}

void	render_fractal(t_fractol *fractol)
{
	t_pixel	pixel;

	pixel.x = 0;
	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			color_pixel(pixel, fractol);
			pixel.x += 1;
		}
		pixel.y += 1;
	}
	mlx_put_image_to_window(
		fractol->mlx_ptr,
		fractol->win_ptr,
		fractol->img.img_ptr,
		0, 0);
}
