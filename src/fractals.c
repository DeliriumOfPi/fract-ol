#include "fractol.h"

int	mandelbrot(t_complex *c, int max_iter);
{
	double	zr;
	double	zi;
	double	temp;
	int		iter;

	zr = 0;
	zi = 0;
	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter++ < max_iter)
	{
		temp = zr * zr - zi * zi + c->re;
		zi = 2 * zr * zi + c->im;
		zr = temp;
	}
	return (iter);
}

int	julia(t_complex *z0, t_complex *c, int max_iter)
{
	double	zr;
	double	zi;
	double	temp;
	int		iter;

	zr = z0->re;
	zi = z0->im;
	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter++ < max_iter)
	{
		temp = zr * zr - zi * zi + c->re;
		zi = 2 * zr * zi + c->im;
		zr = temp;
	}
	return (iter);
}

int	newton(t_complex *z0, int max_iter)
{
	t_complex	z;
	t_complex	f;
	t_complex	f_prime;
	int			iter;

	z.re = z0->re;
	z.im = z0->im;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter++ < max_iter)
	{
		f.re = z.re * z.re * z.re - 3 * z.im * z.im - 1;
        f.im = 3 * z.re * z.re * z.im - z.im * z.im * z.im;        
        f_prime.re = 3 * (z.re * z.re - z.im * z.im);
        f_prime.im = 6 * z.re * z.im;
        denom = f_prime.re * f_prime.re + f_prime.im * f_prime.im;
        z.re -= (f.re * f_prime.re + f.im * f_prime.im) / 
			f_prime.re * f_prime.re + f_prime.im * f_prime.im;
        z.im -= (f.im * f_prime.re - f.re * f_prime.im) /
			f_prime.re * f_prime.re + f_prime.im * f_prime.im;
    }
    return iter;
}

int	burning_ship(t_complex *c, int max_iter)
{
	double	zr;
	double	zi;
	double	temp;
	int		iter;

	zr = 0;
	zi = 0;
	while (zr * zr + zi * zi <= 4 && iter++ < max_iter)
	{
		temp = fabs(zr * zr - zi * zi) + c->re;
		zi = fabs(2 * zr * zi) + c->im;
		zr = temp;
	}
	return (iter);
}

int	phoenix(t_complex *z0, t_complex *c, t_complex *p, int max_iter)
{
	t_complex	z;
	t_complex	prev_z;
	t_complex	temp;
	int		iter;

	z.re = z0->re;
	z.im = z0->im;
	prev_z.re = 0;
	prev z.im = 0;
	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter++ < max_iter)
	{
		temp.re = z.re * z.re + z.im * z.im + c->re +
			p->re * prev_z.re + p->im * prev_z.im;
		temp.im = 2 * z.re * z.im + c->im +
			p->im * prev_z.re + p->re * prev_z.im;
		prev_z = z;
		z = temp;
	}
	return (iter);
}
