/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:27:01 by bosco             #+#    #+#             */
/*   Updated: 2024/12/10 17:54:50 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_fractol *data, char **argv)
{
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
	{
		data->fractal_type = MANDELBROT;
		data->max_x = 1.0;
		data->min_y = -1.5;
		data->max_y = 1.5;
	}
	else if (!ft_strncmp(argv[1], "julia", 5))
	{
		data->fractal_type = JULIA;
		data->julia_c.real = ft_atof(argv[2]);
		data->julia_c.imag = ft_atof(argv[3]);
		data->max_x = 2.0;
		data->min_y = -2.0;
		data->max_y = 2.0;
	}
	else if (!ft_strncmp(argv[1], "burningship", 11))
	{
		data->fractal_type = BURNING_SHIP;
		data->max_x = 2.0;
		data->min_y = -2.0;
		data->max_y = 2.0;
	}
	data->min_x = -2.0;
	data->max_iter = 50;
}

void	init_mlx(t_fractol *data)
{
	int	*l_len;
	int	*bpp;

	bpp = &data->bpp;
	l_len = &data->line_len;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fractol");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img_ptr, bpp, l_len, &data->endian);
}
