/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:34:08 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 20:39:31 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_put_pixel(t_img *img, t_pixel pixel, int color)
{
	int		x;
	int		y;
	char	*pix;

	x = pixel.x;
	y = pixel.y;
	pix = img->img_addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pix = color;
}
