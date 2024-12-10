/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:07:56 by bosco             #+#    #+#             */
/*   Updated: 2024/12/10 13:17:15 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	right_movement(t_fractol *data, double range_x)
{
	data->min_x += range_x * 0.1;
	data->max_x += range_x * 0.1;
}

void	left_movement(t_fractol *data, double range_x)
{
	data->min_x -= range_x * 0.1;
	data->max_x -= range_x * 0.1;
}

void	up_movement(t_fractol *data, double range_y)
{
	data->min_y -= range_y * 0.1;
	data->max_y -= range_y * 0.1;
}

void	down_movement(t_fractol *data, double range_y)
{
	data->min_y += range_y * 0.1;
	data->max_y += range_y * 0.1;
}

void	handle_arrow_keys(int keysym, t_fractol *data)
{
	double	range_x;
	double	range_y;

	range_x = data->max_x - data->min_x;
	range_y = data->max_y - data->min_y;
	if (keysym == XK_Left)
		left_movement(data, range_x);
	else if (keysym == XK_Right)
		right_movement(data, range_x);
	else if (keysym == XK_Up)
		up_movement(data, range_y);
	else if (keysym == XK_Down)
		down_movement(data, range_y);
	draw_fractal(data);
}
