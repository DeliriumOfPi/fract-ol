#include "../include/fractol.h"

void	key_movement_hook(mlx_key_data_t *keydata, t_fractal *frac)
{
    double move_step;

	move_step = (frac->c_max.re - frac->c_min.re) * MOVE_STEP_FACTOR;
	if (keydata->key == MLX_KEY_UP)
	{ 
		frac->c_min.im -= move_step;
		frac->c_max.im -= move_step;
	}
    else if (keydata->key == MLX_KEY_DOWN)
	{
		frac->c_min.im += move_step;
		frac->c_max.im += move_step;
	}
    else if (keydata->key == MLX_KEY_LEFT)
	{
		frac->c_min.re -= move_step;
		frac->c_max.re -= move_step;
	}
    else if (keydata->key == MLX_KEY_RIGHT)
	{
		frac->c_min.re += move_step;
		frac->c_max.re += move_step;
	}
}

void	key_zoom_hook(mlx_key_data_t *keydata, t_fractal *frac)
{
	t_complex fix;

	fix.re = (frac->c_max.re + frac->c_min.re) / 2;
	fix.im = (frac->c_max.im + frac->c_min.im) / 2;
    if (keydata->key == MLX_KEY_Z)
		zoom(frac, fix, ZOOM_FACTOR);
    else if (keydata->key == MLX_KEY_X)
		zoom(frac, fix, 1/ZOOM_FACTOR);
}

void	key_color_hook(mlx_key_data_t *keydata, t_fractal *frac)
{
	frac->palette = (frac->palette + 1) % COLOR_COUNT;
}

void	key_fractal_hook(mlx_key_data_t *keydata, t_fractal *frac)
{
	frac->type = (frac->type + 1) % FRACTAL_COUNT;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == MLX_PRESS)
	{
    	if (keydata.key == MLX_KEY_ESCAPE)
       		exit(0);
		else if ((keydata.key == MLX_KEY_UP) || (keydata.key == MLX_KEY_DOWN) || 
			(keydata.key == MLX_KEY_LEFT) || (keydata.key == MLX_KEY_RIGHT))
			key_movement_hook(&keydata, (t_fractal *)param);
		else if ((keydata.key == MLX_KEY_Z) || (keydata.key == MLX_KEY_X))
			key_zoom_hook(&keydata, (t_fractal *)param);
    	else if (keydata.key == MLX_KEY_C)
			key_color_hook(&keydata, (t_fractal *)param);
	    else if (keydata.key == MLX_KEY_F)
			key_fractal_hook(&keydata, (t_fractal *)param);
    	//mlx_image_to_window(frac->mlx, frac->img, 0, 0);
	}
}
