/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msottana <msottana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:04:04 by msottana          #+#    #+#             */
/*   Updated: 2025/04/13 19:50:15 by msottana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(mlx_t	*mlx, char *error_msg)
{
	if (mlx != NULL)
		mlx_terminate(*mlx);
	if (error_msg != NULL)

	exit(EXIT_FAILURE);
}

void	init_fractal(int argc, char *argv[], t_fractal *frac)
{
	if (argc < 2)
		ft_error(NULL, 
				"Se necesita al menos un argumento para indicar el tipo del fractal:\n
				"

	frac.type = 
}

void	init_mlx(t_fractal *frac)
{

}

void	ft_hook(void *param)
{
	t_fractal *frac = (t_fractal *)param;

	draw_fractal(frac);
}

int	main(int argc, char *argv[])
{
	t_fractal	frac;

    frac.mlx = mlx_init(WIDTH, HEIGHT, "Fractal Viewer", true);
    frac.img = mlx_new_image(frac.mlx, WIDTH, HEIGHT);
    mlx_image_to_window(frac.mlx, frac.img, 0, 0);

    frac.type = MANDELBROT;
    frac.c_min.re = -2.0; frac.c_max.re = 1.0;
    frac.c_min.im = -1.2; frac.c_max.im = frac.c_min.im + (frac.c_max.re - frac.c_min.re) * HEIGHT / WIDTH;
    //frac.julia_z.re = -0.7; frac.julia_z.im = 0.27015;
	frac.julia_z.re = 0.5667; frac.julia_z.im = 0;
	frac.phoenix_p.re = -0.5; frac.phoenix_p.im= 0;
    frac.c_min.re = -2.5; frac.c_max.re = 1.0;
    frac.c_min.im = -1; frac.c_max.im = 1.0;//frac.c_min.im + (frac.c_max.re - frac.c_min.re) * HEIGHT / WIDTH;
    frac.width = WIDTH;
	frac.height = HEIGHT;
	frac.palette = FIRE;
	frac.max_iter = DEFAULT_ITER;
	frac.mouse_down = false;


    draw_fractal(&frac);
	mlx_loop_hook(frac.mlx, ft_hook, &frac);
    mlx_key_hook(frac.mlx, key_hook, &frac);
	mlx_scroll_hook(frac.mlx, scroll_hook, &frac);
	mlx_mouse_hook(frac.mlx, mouse_down_hook, &frac);
	mlx_cursor_hook(frac.mlx, mouse_move_hook, &frac);
	mlx_resize_hook(frac.mlx, resize_hook, &frac);
    mlx_loop(frac.mlx);
    mlx_terminate(frac.mlx);
    return EXIT_SUCCESS;
}
