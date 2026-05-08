/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmansour <wmmansouri@insea.ac.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:41:29 by wmansour          #+#    #+#             */
/*   Updated: 2025/02/03 20:44:31 by wmansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	write_str(USAGE_0);
	write_str(USAGE_1);
	write_str(USAGE_2);
}

static int	setup_julia(int argc, char **argv, t_fractol *fractol)
{
	fractol->type = JULIA;
	fractol->julia = (t_complex){-0.8, 0.156};
	if (argc == 2)
		return (TRUE);
	if (argc == 4 && parse_double(argv[2], &fractol->julia.re)
		&& parse_double(argv[3], &fractol->julia.im))
		return (TRUE);
	return (FALSE);
}

static int	parse_args(int argc, char **argv, t_fractol *fractol)
{
	if ((argc == 2 || argc == 4) && str_equal(argv[1], "julia"))
		return (setup_julia(argc, argv, fractol));
	if (argc == 2 && str_equal(argv[1], "mandelbrot_2"))
	{
		fractol->type = MANDELBROT_2;
		return (TRUE);
	}
	if (argc == 2 && str_equal(argv[1], "mandelbrot_3"))
	{
		fractol->type = MANDELBROT_3;
		return (TRUE);
	}
	return (FALSE);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	init_fractol(&fractol);
	if (!parse_args(argc, argv, &fractol))
		return (print_usage(), 1);
	init_graphics(&fractol);
	render_fractal(&fractol);
	mlx_loop(fractol.mlx_ptr);
	return (0);
}
