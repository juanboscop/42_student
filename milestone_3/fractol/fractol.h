/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:36:45 by bosco             #+#    #+#             */
/*   Updated: 2024/12/10 18:40:43 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> // debugging
# include <unistd.h> // write
# include <stdlib.h> // malloc free
# include <math.h> 
# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"
# include "libft/libft.h"

# define ERROR_MSG "\nPlease enter a correct julia , mandelbrot or burningship sequence\n"
# define WIDTH 800
# define HEIGHT 800

enum	e_fractal_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP
};

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractol
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;

	double				min_x;
	double				max_x;
	double				min_y;
	double				max_y;

	enum e_fractal_type	fractal_type;
	t_complex			julia_c;
	int					max_iter;

}	t_fractol;

// Initialization
void	init_data(t_fractol *data, char **argv);
void	init_mlx(t_fractol *data);
void	set_hooks(t_fractol *data);

// Drawing & Fractals
void	draw_fractal(t_fractol *data);
int		mandelbrot_iter_count(double x, double y, int max_iter);
int		julia_iter_count(double x, double y, t_complex c, int max_iter);
int		burning_ship_iter_count(double x, double y, int max_iter);

// Events & Zoom
int		handle_key(int keysym, t_fractol *data);
int		handle_mouse(int button, int x, int y, t_fractol *data);
void	apply_zoom(t_fractol *data, double mouse_x, double mouse_y, double zf);
void	handle_arrow_keys(int keysym, t_fractol *data);

// Utilities
void	put_pixel(t_fractol *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		close_window(t_fractol *data);

// cleanup
void	cleanup(t_fractol *data);

#endif