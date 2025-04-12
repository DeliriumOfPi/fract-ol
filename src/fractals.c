#include "fractol.h"


#include <stdio.h>
int	mandelbrot(t_complex *c, int max_iter)
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
	//printf("c = %.2f+i%.2f, zr = %.2f, zi = %.2f, iter = %d\n", c->re, c->im, zr, zi, iter);
	
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
	t_complex	diff;
	int			iter;
	//double		denom;

	z.re = z0->re;
	z.im = z0->im;
	diff.re = z.re;
	diff.im = z.im;
	iter = 0;
	while (diff.re * diff.re + diff.im * diff.im > 1e-10 && iter++ < max_iter) //Scale with zoom the error
	//while (iter++ < max_iter)
	{
		f.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im - 1;
        f.im = 3 * z.re * z.re * z.im - z.im * z.im * z.im;        
        f_prime.re = 3 * (z.re * z.re - z.im * z.im);
        f_prime.im = 6 * z.re * z.im;
        //denom = f_prime.re * f_prime.re + f_prime.im * f_prime.im;
        diff.re = (f.re * f_prime.re + f.im * f_prime.im) / 
			(f_prime.re * f_prime.re + f_prime.im * f_prime.im);
        diff.im = (f.im * f_prime.re - f.re * f_prime.im) /
			(f_prime.re * f_prime.re + f_prime.im * f_prime.im); 
		z.re -= diff.re;
		z.im -= diff.im;
    }
	//printf("%.2f, %.2f %d\n", f.re * f_prime.re + f.im * f_prime.im, f.im * f_prime.re - f.re * f_prime.im, iter);
    return (atan2(z.im, z.re) / (2.0 * M_PI) + 0.5) * max_iter;
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
	prev_z.im = 0;
	iter = 0;
	/*while (zr * zr + zi * zi <= 4 && iter++ < max_iter)
	{
		temp.re = z.re * z.re + z.im * z.im + c->re +
			p->re * prev_z.re + p->im * prev_z.im;
		temp.im = 2 * z.re * z.im + c->im +
			p->im * prev_z.re + p->re * prev_z.im;
		prev_z = z;
		z = temp;
	}*/
	return (iter);
}
