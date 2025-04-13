/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msottana <msottana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:21:35 by msottana          #+#    #+#             */
/*   Updated: 2025/04/12 22:01:58 by msottana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <math.h>

//# define WIDTH 64
//# define HEIGHT 48
//# define WIDTH 640
//# define HEIGHT 480

//# define WIDTH 800
//# define HEIGHT 600
# define WIDTH 1024
# define HEIGHT 768
//# define WIDTH 1280
//# define HEIGHT 960
//# define WIDTH 1440
//# define HEIGHT 1080
//# define WIDTH 1920
//# define HEIGHT 1440

//# define WIDTH 1920
//# define HEIGHT 1080
# define DEFAULT_ITER 640
# define MOVE_STEP_FACTOR 0.1
# define ZOOM_FACTOR 0.8

typedef enum	e_fractal_type
{
	MANDELBROT,
	JULIA,
	NEWTON,
	BURNING_SHIP,
	PHOENIX,
	FRACTAL_COUNT
} t_fractal_type;

typedef enum	e_palette
{
	GRAYSCALE,
	PASTEL,
	ICE,
	OCEAN,
	CYBER,
	ELECTRIC,
	PSYCHEDELIC,
	RAINBOW,
	SUNSET,
	INFERNO,
	FIRE,
	MAGENTA,
	REDSCALE,
	BLACKWHITE,
	COLOR_COUNT
} t_palette;

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
	t_complex		c_min;
	t_complex		c_max;
	t_complex		julia_z;
	t_complex		phoenix_p;
	t_palette		palette;
	int				width;
	int				height;
	int				max_iter;
	bool			mouse_down;
	double				mouse_x;
	double				mouse_y;
} t_fractal;

int			mandelbrot(t_complex *c, int max_iter);
int			julia(t_complex *z, t_complex *c, int max_iter);
int			newton(t_complex *z, double threshold, int max_iter);
int			burning_ship(t_complex *c, int max_iter);
int			phoenix(t_complex *z0, t_complex *c, t_complex *p, int max_iter);
void		draw_fractal(t_fractal *fractal);
uint32_t	color_palette(int iter, int max_iter, t_palette palette);
void		key_hook(mlx_key_data_t keydata, void *param);
void		scroll_hook(double xdelta, double ydelta, void *param);
void		mouse_down_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param);
void		mouse_move_hook(double xpos, double ypos, void *param);
void		resize_hook(int32_t width, int32_t height, void *param);
void		zoom(t_fractal *frac, t_complex fix, double z);


#endif
