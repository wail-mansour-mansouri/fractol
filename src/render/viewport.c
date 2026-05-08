/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:48:08 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 17:16:03 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fit_view_to_window(t_fractol *fractol)
{
	if (WIDTH > HEIGHT)
	{
		fractol->re_max = RE_MAX * (double)WIDTH / (double)HEIGHT;
		fractol->re_min = RE_MIN * (double)WIDTH / (double)HEIGHT;
	}
	else if (WIDTH < HEIGHT)
	{
		fractol->im_max = IM_MAX * (double)HEIGHT / (double)WIDTH;
		fractol->im_min = IM_MIN * (double)HEIGHT / (double)WIDTH;
	}
}
