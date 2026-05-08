/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:42:59 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 18:13:04 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->img.endian = 0;
	fractol->img.img_ptr = NULL;
	fractol->img.img_addr = NULL;
	fractol->img.size_line = 0;
	fractol->img.bits_per_pixel = 0;
	fractol->zoom = 1.0;
	fractol->type = MANDELBROT_2;
	fractol->julia = (t_complex){-0.8, 0.156};
	fractol->im_max = IM_MAX;
	fractol->im_min = IM_MIN;
	fractol->re_max = RE_MAX;
	fractol->re_min = RE_MIN;
	fractol->mlx_ptr = NULL;
	fractol->win_ptr = NULL;
	fractol->max_iter = MAX_ITER;
	fractol->color_shift = 0.0;
}

void	init_graphics(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	if (fractol->mlx_ptr == NULL)
		exit_cleanly("Error: mlx_init() failed\n", 1, fractol);
	fractol->win_ptr = mlx_new_window(
			fractol->mlx_ptr,
			WIDTH,
			HEIGHT,
			"Fractol");
	if (fractol->win_ptr == NULL)
		exit_cleanly("Error: mlx_new_window() failed\n", 1, fractol);
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (fractol->img.img_ptr == NULL)
		exit_cleanly("Error: mlx_new_image() failed\n", 1, fractol);
	fractol->img.img_addr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bits_per_pixel, &fractol->img.size_line,
			&fractol->img.endian);
	if (fractol->img.img_addr == NULL)
		exit_cleanly("Error: mlx_get_data_addr() failed\n", 1, fractol);
	init_view(fractol);
	setup_hooks(fractol);
}
