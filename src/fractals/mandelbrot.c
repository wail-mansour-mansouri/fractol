/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:55:21 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 20:35:38 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_is_in	is_in_mandelbrot_2(t_complex x, int max_iter)
{
	int			i;
	t_complex	z;

	i = 0;
	z = (t_complex){0, 0};
	while (i < max_iter)
	{
		z = complex_add(complex_square(z), x);
		if (complex_abs2(z) > 4)
			return ((t_is_in){FALSE, i});
		i += 1;
	}
	return ((t_is_in){TRUE, i});
}

t_is_in	is_in_mandelbrot_3(t_complex x, int max_iter)
{
	int			i;
	t_complex	z;

	i = 0;
	z = (t_complex){0, 0};
	while (i < max_iter)
	{
		z = complex_add(complex_mul(z, complex_square(z)), x);
		if (complex_abs2(z) > 4)
			return ((t_is_in){FALSE, i});
		i += 1;
	}
	return ((t_is_in){TRUE, i});
}
