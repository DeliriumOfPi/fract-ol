#include "../include/fractol.h"

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractal *f = (t_fractal *)param;
	double zoom_factor = 0.8;
	double mouse_re, mouse_im;

	int mx, my;
	mlx_get_mouse_pos(f->mlx, &mx, &my);

	t_complex fix;
	fix.re = f->c_min.re + ((double)mx / f->img->width) * (f->c_max.re - f->c_min.re);
	fix.im = f->c_min.im + ((double)my / f->img->height) * (f->c_max.im - f->c_min.im);

	if (ydelta > 0)
		zoom(f, fix, zoom_factor);
	else
		zoom(f, fix, 1/zoom_factor);	
}

void mouse_down_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_fractal *frac = (t_fractal *)param;

	if (button == MLX_MOUSE_BUTTON_LEFT)
	{
		if (action == MLX_PRESS)
			frac->mouse_down = true;
		else if (action == MLX_RELEASE)
			frac->mouse_down = false;
	}
}

void mouse_move_hook(double xpos, double ypos, void *param)
{
	t_fractal *frac = (t_fractal *)param;

	if (frac->mouse_down)
	{
		double dx = ((frac->mouse_x - xpos) / frac->img->width) * (frac->c_max.re - frac->c_min.re);
		double dy = ((frac->mouse_y - ypos) / frac->img->height) * (frac->c_max.im - frac->c_min.im);

		frac->c_min.re += dx;
		frac->c_max.re += dx;
		frac->c_min.im += dy;
		frac->c_max.im += dy;
	}

	frac->mouse_x = xpos;
	frac->mouse_y = ypos;
}

void resize_hook(int32_t width, int32_t height, void *param)
{
	t_fractal *frac = (t_fractal *)param;

	mlx_resize_image(frac->img, width, height);
	frac->width = width;
	frac->height = height;
}
