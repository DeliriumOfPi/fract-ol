/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msottana <msottana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:04:04 by msottana          #+#    #+#             */
/*   Updated: 2025/03/30 16:04:06 by msottana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_hook(void *param)
{
	t_fractal *frac = (t_fractal *)param;

	draw_fractal(frac);
}

int	main(int args, char *argv[])
{
	t_fractal	frac;

    frac.mlx = mlx_init(WIDTH, HEIGHT, "Fractal Viewer", true);
    frac.img = mlx_new_image(frac.mlx, WIDTH, HEIGHT);
    mlx_image_to_window(frac.mlx, frac.img, 0, 0);

    frac.type = MANDELBROT;
	//frac.type = JULIA;
	//frac.type = NEWTON;
	//frac.type = BURNING_SHIP;
    frac.c_min.re = -2.0; frac.c_max.re = 1.0;
    frac.c_min.im = -1.2; frac.c_max.im = frac.c_min.im + (frac.c_max.re - frac.c_min.re) * HEIGHT / WIDTH;
    frac.julia_z.re = -0.7; frac.julia_z.im = 0.27015;
    frac.width = WIDTH;
	frac.height = HEIGHT;
	frac.palette = FIRE;
	frac.max_iter = DEFAULT_ITER;


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
