/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:06:50 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 17:07:36 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool	int_array_contains(int x, int *array)
{
	int	i;

	i = 0;
	while (array[i] != -1)
	{
		if (x == array[i])
			return (TRUE);
		i += 1;
	}
	return (FALSE);
}
