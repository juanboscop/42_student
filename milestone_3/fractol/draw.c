/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:48:46 by bosco             #+#    #+#             */
/*   Updated: 2024/12/09 17:48:49 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_pixel(t_fractol *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

int create_trgb(int t, int r, int g, int b)
{
    return ((t << 24) | (r << 16) | (g << 8) | b);
}

void draw_fractal(t_fractol *data)
{
    int x, y;
    double cx, cy;
    int iter;
    int color;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            cx = data->min_x + (x / (double)WIDTH) * (data->max_x - data->min_x);
            cy = data->min_y + (y / (double)HEIGHT) * (data->max_y - data->min_y);
            if (data->fractal_type == MANDELBROT)
                iter = mandelbrot_iter_count(cx, cy, data->max_iter);
            else
                iter = julia_iter_count(cx, cy, data->julia_c, data->max_iter);
            
            // Simple coloring: black if in set, else based on iteration
            if (iter == data->max_iter)
                color = create_trgb(0, 0, 0, 0);
            else
                color = create_trgb(0, (iter * 5) % 255, (iter * 9) % 255, (iter * 15) % 255);

            put_pixel(data, x, y, color);
        }
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
