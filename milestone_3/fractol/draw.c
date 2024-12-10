/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:48:46 by bosco             #+#    #+#             */
/*   Updated: 2024/12/10 17:49:57 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return ((t << 24) | (r << 16) | (g << 8) | b);
}

int	calculate_color(t_fractol *data, double cx, double cy)
{
	int	iter;
	int	color;
	int	color_2nd;

	if (data->fractal_type == MANDELBROT)
		iter = mandelbrot_iter_count(cx, cy, data->max_iter);
	else if (data->fractal_type == JULIA)
		iter = julia_iter_count(cx, cy, data->julia_c, data->max_iter);
	else if (data->fractal_type == BURNING_SHIP)
		iter = burning_ship_iter_count(cx, cy, data->max_iter);
	color_2nd = (iter * 5) % 255;
	if (iter == data->max_iter)
		color = create_trgb(0, 0, 0, 0);
	else
		color = create_trgb(0, color_2nd, (iter * 9) % 255, (iter * 15) % 255);
	return (color);
}

void	draw_pixel_row(t_fractol *data, int y)
{
	int		x;
	double	cx;
	double	cy;
	int		color;

	x = 0;
	while (x < WIDTH)
	{
		cx = data->min_x + (x / (double)WIDTH) * (data->max_x - data->min_x);
		cy = data->min_y + (y / (double)HEIGHT) * (data->max_y - data->min_y);
		color = calculate_color(data, cx, cy);
		put_pixel(data, x, y, color);
		x++;
	}
}

void	draw_fractal(t_fractol *data)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		draw_pixel_row(data, y);
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
