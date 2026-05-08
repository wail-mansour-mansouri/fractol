/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:58:21 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 16:28:02 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static double	integer_part(char *str, int *i)
{
	double	result;

	result = 0.0;
	while (is_digit(str[*i]))
	{
		result = result * 10.0 + (double)(str[*i] - '0');
		*i += 1;
	}
	return (result);
}

t_bool	parse_double(char *str, double *result)
{
	int		i;
	double	sign;
	double	divisor;
	int		digits;

	i = 0;
	sign = 1.0;
	divisor = 10.0;
	digits = 0;
	*result = 0.0;
	if (str[i] == '+')
		i += 1;
	else if (str[i] == '-')
	{
		i += 1;
		sign = -1.0;
	}
	while (is_digit(str[i + digits]))
		digits += 1;
	*result = integer_part(str, &i);
	if (str[i] == '.')
	{
		i += 1;
		while (is_digit(str[i]))
		{
			*result += (double)(str[i] - '0') / divisor;
			divisor *= 10.0;
			digits += 1;
			i += 1;
		}
	}
	*result *= sign;
	return (digits > 0 && str[i] == 0);
}
