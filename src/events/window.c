/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:56:22 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 16:57:03 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_event(t_fractol *fractol)
{
	exit_cleanly("Exit: cross button pressed\n", 0, fractol);
	return (0);
}

int	expose_event(t_fractol *fractol)
{
	render_fractal(fractol);
	return (0);
}
