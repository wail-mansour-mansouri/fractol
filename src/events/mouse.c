/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:09:52 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 19:46:30 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom_event(int button, int x, int y, t_fractol *fractol)
{
	t_complex	c;
	double		zoom_factor;

	c = pixel_to_complex((t_pixel){x, y}, fractol);
	if (button == 5)
		zoom_factor = 1.7;
	else if (button == 4)
		zoom_factor = 1 / 1.7;
	else
		return (0);
	fractol->re_min = c.re - (c.re - fractol->re_min) * zoom_factor;
	fractol->re_max = c.re - (c.re - fractol->re_max) * zoom_factor;
	fractol->im_min = c.im - (c.im - fractol->im_min) * zoom_factor;
	fractol->im_max = c.im - (c.im - fractol->im_max) * zoom_factor;
	render_fractal(fractol);
	return (0);
}

int	mouse_move_event(int x, int y, t_fractol *fractol)
{
	if (fractol->type != JULIA)
		return (0);
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	fractol->julia = pixel_to_complex((t_pixel){x, y}, fractol);
	render_fractal(fractol);
	return (0);
}
