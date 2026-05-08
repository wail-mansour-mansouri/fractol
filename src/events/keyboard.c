/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:57:48 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 21:03:54 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_event(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
		exit_cleanly("Exit: esc key pressed\n", 0, fractol);
	else if (int_array_contains(keycode, (int []){UP, DOWN, LEFT, RIGHT, -1}))
		shift_event(keycode, fractol);
	else if (keycode == PLUS)
	{
		fractol->max_iter += 10;
		if (fractol->max_iter > 300)
			fractol->max_iter = 300;
	}
	else if (keycode == MINUS)
	{
		fractol->max_iter -= 10;
		if (fractol->max_iter < 10)
			fractol->max_iter = 10;
	}
	else if (keycode == SPACE)
	{
		fractol->color_shift += 0.05;
		if (fractol->color_shift > 0.7)
			fractol->color_shift = 0.0;
	}
	render_fractal(fractol);
	return (0);
}
