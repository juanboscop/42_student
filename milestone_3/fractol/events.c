/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:30:16 by bosco             #+#    #+#             */
/*   Updated: 2024/12/10 13:50:30 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *data)
{
	cleanup(data);
	exit(0);
	return (0);
}

int	handle_key(int keysym, t_fractol *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	else if (keysym == XK_i)
	{
		data->max_iter += 10;
		draw_fractal(data);
	}
	else if (keysym == XK_Left || keysym == XK_Right
		|| keysym == XK_Up || keysym == XK_Down)
	{
		handle_arrow_keys(keysym, data);
	}
	return (0);
}

void	apply_zoom(t_fractol *data, double mouse_x, double mouse_y, double zf)
{
	double	range_x;
	double	range_y;
	double	c_x;
	double	c_y;
	double	new_range_y;

	range_x = data->max_x - data->min_x;
	range_y = data->max_y - data->min_y;
	c_x = data->min_x + (mouse_x / (double)WIDTH) * range_x;
	c_y = data->min_y + (mouse_y / (double)HEIGHT) * range_y;
	new_range_y = range_y * zf;
	data->min_x = c_x - ((range_x * zf) * (mouse_x / (double)WIDTH));
	data->max_x = data->min_x + (range_x * zf);
	data->min_y = c_y - (new_range_y * (mouse_y / (double)HEIGHT));
	data->max_y = data->min_y + new_range_y;
}

int	handle_mouse(int button, int x, int y, t_fractol *data)
{
	if (button == 4)
		apply_zoom(data, x, y, 0.9);
	else if (button == 5)
		apply_zoom(data, x, y, 1.1);
	draw_fractal(data);
	return (0);
}

void	set_hooks(t_fractol *data)
{
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, handle_key, data);
	mlx_mouse_hook(data->win_ptr, handle_mouse, data);
}
