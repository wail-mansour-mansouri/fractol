/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:26:57 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 20:27:37 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_mul(t_complex a, t_complex b)
{
	double	re;
	double	im;

	re = a.re * b.re - a.im * b.im;
	im = a.re * b.im + a.im * b.re;
	return ((t_complex){re, im});
}
