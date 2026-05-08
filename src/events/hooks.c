/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:52:01 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 19:42:49 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_hooks(t_fractol *fractol)
{
	mlx_hook(fractol->win_ptr, ON_DESTROY, 0, close_event, fractol);
	mlx_hook(fractol->win_ptr, ON_EXPOSE, EXPOSURE_MASK, expose_event,
		fractol);
	mlx_hook(fractol->win_ptr, ON_KEYDOWN, KEY_PRESS_MASK, key_event, fractol);
	mlx_hook(fractol->win_ptr, ON_MOUSEDOWN, BUTTON_PRESS_MASK, zoom_event,
		fractol);
	mlx_hook(fractol->win_ptr, ON_MOUSEMOVE, POINTER_MOTION_MASK,
		mouse_move_event, fractol);
}
