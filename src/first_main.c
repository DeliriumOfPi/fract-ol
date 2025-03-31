/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msottana <msottana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:24:59 by msottana          #+#    #+#             */
/*   Updated: 2025/03/30 17:07:08 by msottana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
//#include <unistd.h>
#include <stdio.h>
#include <math.h>

uint32_t hsv_to_rgb(float h, float s, float v)
{
    float c = v * s;
    float x = c * (1 - fabsf(fmodf(h / 60.0, 2) - 1));
    float m = v - c;

    float r, g, b;
    if (h < 60)      { r = c, g = x, b = 0; }
    else if (h < 120) { r = x, g = c, b = 0; }
    else if (h < 180) { r = 0, g = c, b = x; }
    else if (h < 240) { r = 0, g = x, b = c; }
    else if (h < 300) { r = x, g = 0, b = c; }
    else             { r = c, g = 0, b = x; }

    uint8_t R = (uint8_t)((r + m) * 255);
    uint8_t G = (uint8_t)((g + m) * 255);
    uint8_t B = (uint8_t)((b + m) * 255);

    return (R << 24) | (G << 16) | (B << 8) | 0xFF; // RGBA format
}

// Print the window width and height.
static void ft_hook(void* param)
{
	//const mlx_t* mlx = param;
	//printf("hook: %p\n", param);
	//printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
	double unit = 0xFFFFFF / ((WIDTH-1) * (HEIGHT-1));
	//uint32_t color = 0xF0F0F0FF;
	for (double x=0; x<WIDTH; x++)
	{
		for (double y=0; y<HEIGHT; y++)
		{
			/*//printf("color in (%d, %d): %X\n", (int)x, (int)y, (unsigned int)(x / (WIDTH - 1) * y / (HEIGHT - 1) * 0xFFFFFFFF));
			//mlx_put_pixel(param, x, y, (unsigned int)(x * y * unit));
			uint32_t color = ((uint32_t)(x * y * unit) << 2) | 0xFF;
			mlx_put_pixel(param, x, y, color);*/

	        /*uint8_t r = (uint8_t)(255 * (x / (double)WIDTH));
	        uint8_t g = (uint8_t)(255 * (y / (double)HEIGHT));
		    uint8_t b = (uint8_t)(255 * ((x + y) / (double)(WIDTH + HEIGHT)));

			uint32_t color = (r << 24) | (g << 16) | (b << 8) | 0xFF; // RGBA format
	        mlx_put_pixel(param, x, y, color);*/

            float hue = (x / (float)WIDTH) * 360; // Hue (0-360)
            float sat = 1.0;                      // Full saturation
            float val = 1.0 - (y / (float)HEIGHT) * 0.5; // Gradient brightness

            uint32_t color = hsv_to_rgb(hue, sat, val);
            mlx_put_pixel(param, x, y, color);
		}
	}
}

void ft_close(void *param)
{
    mlx_t *mlx = param;
    mlx_terminate(mlx);
    exit(EXIT_SUCCESS);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	/*// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");*/

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		ft_close(param);
}

int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "My_title", true);
	if (!mlx)
		exit(EXIT_FAILURE);

	/* Do stuff */

	// Create and display the image.
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	ft_hook(img);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	{
		//ft_error();
		//free(mlx);
		mlx_terminate(mlx);
		exit(EXIT_FAILURE);
	}

	// Even after the image is being displayed, we can still modify the buffer.
	//mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	//printf("%p\n", img);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	//mlx_loop_hook(mlx, ft_hook, img);
	//mlx_key_hook(mlx, my_keyhook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
