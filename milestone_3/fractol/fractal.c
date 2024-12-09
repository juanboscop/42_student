/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:28:11 by bosco             #+#    #+#             */
/*   Updated: 2024/12/09 13:28:16 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot_iter_count(double x, double y, int max_iter)
{
    double zx = 0.0;
    double zy = 0.0;
    double zx2 = 0.0;
    double zy2 = 0.0;
    int i = 0;

    while (i < max_iter && (zx2 + zy2) <= 4.0)
    {
        zy = 2 * zx * zy + y;
        zx = zx2 - zy2 + x;
        zx2 = zx * zx;
        zy2 = zy * zy;
        i++;
    }
    return i;
}

int julia_iter_count(double x, double y, t_complex c, int max_iter)
{
    double zx = x;
    double zy = y;
    double zx2, zy2;
    int i = 0;

    while (i < max_iter && (zx*zx + zy*zy) <= 4.0)
    {
        zx2 = zx*zx - zy*zy + c.real;
        zy2 = 2*zx*zy + c.imag;
        zx = zx2;
        zy = zy2;
        i++;
    }
    return i;
}
