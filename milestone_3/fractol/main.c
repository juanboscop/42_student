/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:30:28 by bosco             #+#    #+#             */
/*   Updated: 2024/12/09 20:35:20 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	data;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		init_data(&data, argv);
		init_mlx(&data);           // Initialize MLX, create window & image
		draw_fractal(&data);       // Draw the initial fractal
		set_hooks(&data);          // Set keyboard, mouse, etc. events
		mlx_loop(data.mlx_ptr);
		cleanup(&data);
	}
	else
	{
		ft_putstr(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
