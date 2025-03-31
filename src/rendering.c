uint32_t	palette_1(int t, t_palette palette)
{
	if (palette == GRAYSCALE)
		return ((int)(t * 255) << 16 |
				(int)(t * t * 255) << 8 |
				(int)(t * t * t * 255));
	if (palette == PASTEL)
    	return (((int)((0.8 + 0.2 * t) * 255) << 16) |
				((int)((0.7 + 0.3 * t) * 255) << 8) |
				((int)((0.9 + 0.1 * t) * 255)));
	if (palette == ICE)
		return (((int)((1 - t) * 128) << 16) |
				((int)(t * 255) << 8) |
				((int)((0.8 + 0.2 * t) * 255)));
	if (palette == OCEAN)
		return (((int)(t * 255) << 16) |
				((int)(0.5 * (1 - t) * 255) << 8) |
				(int)((1 - t) * 255));
	return (0xFFFFFFFF);
}

uint32_t	palette_2(int t, t_palette palette)
{
	if (palette == CYBER)
		return (((int)((1 - t) * 255) << 16) |
				((int)(t * 128) << 8) |
				((int)(pow(t, 0.5) * 255)));
	if (palette == ELECTRIC)
		return (((int)(pow(t, 0.3) * 255) << 16) |
				((int)(pow(t, 0.6) * 255) << 8) |
				(int)(pow(t, 0.9) * 255));
	if (palette == PSYCHEDELIC)
		return (((int)(sin(3.0 * t) * 127 + 128) << 16) |
				((int)(sin(5.0 * t) * 127 + 128) << 8) |
				((int)(sin(7.0 * t) * 127 + 128)));
	if (palette == RAINBOW)
		return (((int)(sin(6.28 * t) * 127 + 128) << 16) |
				((int)(sin(6.28 * t + 2.09) * 127 + 128) << 8) |
				((int)(sin(6.28 * t + 4.19) * 127 + 128)));
	return (0xFFFFFFFF);
}

uint32_t	palette_3(int t, t_palette palette)
{
	if (palette == SUNSET)
		return (((int)(t * t * 255) << 16) |
				((int)(t * 255) << 8) |
				(int)(255 - t * 255));
	if (palette == INFERNO)
		return (((int)(exp(t * 2 - 1) * 255) << 16) |
				((int)((1 - t) * 255) << 8) |
				((int)(t * 128)));
	if (palette == FIRE)
		return (((int)(9 * (1 - t) * t * t * t * 255) << 16) |
				((int)(15 * (1 - t) * (1 - t) * t * t * 255) << 8) |
				((int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255)));
	if (palette == MAGENTA)
		return (((int)(t * 255) << 8) |
				((int)(t * t * 255) << 16) |
				(int)(t * 255));
	return (0xFFFFFFFF);
}

uint32_t	color_palette(int iter, int max_iter, t_palette palette)
{
	double	iter_ratio;

	if (iter == max_iter)
		return (0x000000FF);
	if (palette == GRAYSCALE) || (palette == PASTEL) ||
		(palette == ICE) || (palette == OCEAN)
			palette_1(iter_ratio, palette);
	if (palette == CYBER) || (palette == ELECTRIC) ||
		(palette == PSYCHEDELIC) || (palette == RAINBOW)
			palette_2(iter_ratio, palette);
	if (palette == SUNSET) || (palette == INFERNO) ||
		(palette == FIRE) || (palette == MAGENTA)
			palette_3(iter_ratio, palette);
	return (0xFFFFFFFF);
}

void	draw_fractal(t_fractal *frac)
{
	t_complex	w;
	int			x;
	int			y;
	int			iter;
	uint32_t	color;
	
	x = -1;
	y = -1;
    while (++y < HEIGHT)
    {
        while (++x < WIDTH)
        {
			w.re = frac->c_min.re + (x / (double)WIDTH) * (frac->c_max.re - frac->c_min.re);
			w.im = frac->c_min.im + (y / (double)HEIGHT) * (frac->c_max.im - frac->c_min.im);
			if (frac->type == MANDELBROT)
				iter = mandelbrot(&w, &frac->max_iter);
			else if (frac->type == JULIA)
				iter = julia(&w, &frac->julia_z, frac->max_iter);
			else if (frac->type == NEWTON)
				iter = newton(&w, &frac->max_iter);
			else if (frac->type == BURNING_SHIP)
				iter = burning_ship(&w, frac->max_iter);
			else if (frac->type == PHOENIX)
				iter = phoenix(w, &frac->julia_z, &frac->phoenix_p, frac->max_iter);
            color = color_palette(iter, frac->max_iter, frac->palette);
			mlx_put_pixel(frac->img, x, y, color);
            //*(uint32_t *)(frac->img->pixels + (y * frac->img->width + x) * 4) = color;
        }
    }
}
