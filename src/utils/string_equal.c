/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:59:19 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 16:05:57 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool	str_equal(char *str_1, char *str_2)
{
	int	i;

	i = 0;
	while (str_1[i] != 0 && str_2[i] != 0)
	{
		if (str_1[i] != str_2[i])
			return (FALSE);
		i += 1;
	}
	if (str_1[i] != str_2[i])
		return (FALSE);
	return (TRUE);
}
