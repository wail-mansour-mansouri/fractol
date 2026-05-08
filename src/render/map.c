/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:10:36 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 18:15:46 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pixel_to_complex(t_pixel pixel, t_fractol *fractol)
{
	t_complex	c;

	c.re = fractol->re_max - fractol->re_min;
	c.re *= (double)pixel.x;
	c.re /= (double)WIDTH - 1.0;
	c.re += fractol->re_min;
	c.im = fractol->im_max - fractol->im_min;
	c.im *= (double)pixel.y;
	c.im /= (double)HEIGHT - 1.0;
	c.im += fractol->im_min;
	return (c);
}
