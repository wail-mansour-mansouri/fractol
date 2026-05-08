/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:02:04 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 18:04:13 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_is_in	is_in_julia(t_complex x, t_complex c, int max_iter)
{
	int			i;
	t_complex	z;

	i = 0;
	z = x;
	while (i < max_iter)
	{
		z = complex_add(complex_square(z), c);
		if (complex_abs2(z) > 4)
			return ((t_is_in){FALSE, i});
		i += 1;
	}
	return ((t_is_in){TRUE, i});
}
