/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_inverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:23:56 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 17:25:32 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel	complex_to_pixel(t_complex c, t_fractol *fractol)
{
	t_pixel	pixel;

	pixel.x = c.re - fractol->re_min;
	pixel.x *= (double)WIDTH - 1.0;
	pixel.x /= fractol->re_max - fractol->re_min;
	pixel.y = c.im - fractol->im_min;
	pixel.y *= (double)HEIGHT - 1.0;
	pixel.y /= fractol->im_max - fractol->im_min;
	return (pixel);
}
