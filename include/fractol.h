/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msottana <msottana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:21:35 by msottana          #+#    #+#             */
/*   Updated: 2025/03/30 17:58:55 by msottana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <math.c>

# define WIDTH 640
# define HEIGHT 480
//# define WIDTH 1920
//# define HEIGHT 1080
# define DEFAULT_ITER 300

typedef enum	e_fractal_type
{
	MANDELBROT,
	JULIA,
	NEWTON,
	BURNING_SHIP,
	PHOENIX
} t_fractal_type;

typedef struct	s_complex
{
	double	re;
	double	im;
} t_complex;

typedef struct	s_fractal
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_fractal_type	type;
	t_complex		z_min;
	t_complex		z_max;
	t_complex		c;
	int				palette;
	int				max_iter;
}

int			mandelbrot(t_complex z, int max_iter);
int			julia(t_complex z, t_complex c, int max_iter);
int			newton(t_complex z, int max_iter);
int			burning_ship(t_complex z, int max_iter);
int			phoenix(t_complex z, t_complex prev_z, int max_iter);
void		draw_fractal(t_fractal *fractal);
uint32_t	color_palette(int iter, int palette);
void		key_hook(mlx_key_data_t keydata, void *param);
void		scroll_hook(double xdelta, double ydelta, void *param);

#endif
