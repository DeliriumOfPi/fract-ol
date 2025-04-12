#include "fractol.h"

void	zoom(t_fractal *frac, t_complex fix, double z)
{
	double	xi = frac->c_min.re; 
	double	xf = frac->c_max.re; 
	double	yi = frac->c_min.im; 
	double	yf = frac->c_max.im; 

	frac->c_min.re = fix.re - z * (fix.re - xi);
	frac->c_max.re = frac->c_min.re + z * (xf - xi);
	frac->c_min.im = fix.im - z * (fix.im - yi);
	frac->c_max.im = frac->c_min.im + z * (yf - yi);
}
