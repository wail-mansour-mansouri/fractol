/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:45:18 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 20:56:59 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_view(t_fractol *fractol)
{
	fractol->im_min = IM_MIN;
	fractol->im_max = IM_MAX;
	fractol->re_min = RE_MIN;
	fractol->re_max = RE_MAX;
	fit_view_to_window(fractol);
	fractol->zoom = 1.0;
	fractol->color_shift = 0.0;
	fractol->max_iter = MAX_ITER;
}
