/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:02:04 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 17:06:09 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift_event(int keycode, t_fractol *fractol)
{
	double	re_shift;
	double	im_shift;

	re_shift = (fractol->re_max - fractol->re_min) / 20.0;
	im_shift = (fractol->im_max - fractol->im_min) / 20.0;
	if (keycode == UP)
	{
		fractol->im_max += im_shift;
		fractol->im_min += im_shift;
	}
	else if (keycode == DOWN)
	{
		fractol->im_max -= im_shift;
		fractol->im_min -= im_shift;
	}
	else if (keycode == LEFT)
	{
		fractol->re_min -= re_shift;
		fractol->re_max -= re_shift;
	}
	else if (keycode == RIGHT)
	{
		fractol->re_min += re_shift;
		fractol->re_max += re_shift;
	}
}
