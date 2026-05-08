/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cleanly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:28:58 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 16:32:33 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_cleanly(char *str, int status, t_fractol *fractol)
{
	if (fractol && fractol->img.img_ptr != NULL)
		mlx_destroy_image(fractol->mlx_ptr, fractol->img.img_ptr);
	if (fractol && fractol->win_ptr != NULL)
		mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
	if (fractol && fractol->mlx_ptr != NULL)
	{
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
	}
	if (str)
		write_str(str);
	exit(status);
}
