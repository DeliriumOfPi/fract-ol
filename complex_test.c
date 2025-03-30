#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <time.h>  // For timing

#define MAX_ITER 1000

int	gen_mandelbrot(double x, double y)
{
	double complex	c;
	double complex	c0;
	int				iter;
	c = 0;
	c0 = x + y * I;
	iter = 1;
	while (iter < MAX_ITER)
	{
		if (cabs(c) > 2)
			return (iter);
		c = c * c + c0;
		iter++;
	}
	return (0);
}

// ---------- Mandelbrot with Complex Numbers ----------
int mandelbrot_complex(double complex c)
{
    double complex z = 0.0 + 0.0 * I;
    int iter = 0;
    while (cabs(z) <= 2.0 && iter < MAX_ITER)
    {
        z = z * z + c;
        iter++;
    }
    return iter;
}

// ---------- Mandelbrot with Real and Imaginary Parts ----------
int mandelbrot_manual(double re, double im)
{
    double zr = 0.0, zi = 0.0;
    int iter = 0;
    while (zr * zr + zi * zi <= 4.0 && iter < MAX_ITER)
    {
        double temp = zr * zr - zi * zi + re;
        zi = 2 * zr * zi + im;
        zr = temp;
        iter++;
    }
    return iter;
}

// ---------- Timer Function ----------
void test_mandelbrot()
{
    int width = 800;
    int height = 600;
    
    // Start timing for mandelbrot_complex
    clock_t start = clock();
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            double re = -2.0 + (x / (double)width) * 3.0;
            double im = -1.5 + (y / (double)height) * 3.0;
            double complex c = re + im * I;
            mandelbrot_complex(c);  // Call mandelbrot with complex numbers
        }
    }
    clock_t end = clock();
    double time_complex = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for Mandelbrot with complex numbers: %.6f seconds\n", time_complex);
    
    // Start timing for mandelbrot_manual
    start = clock();
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            double re = -2.0 + (x / (double)width) * 3.0;
            double im = -1.5 + (y / (double)height) * 3.0;
            mandelbrot_manual(re, im);  // Call mandelbrot with manual real/imag
        }
    }
    end = clock();
    double time_manual = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for Mandelbrot with real/imaginary: %.6f seconds\n", time_manual);

    // Start timing for custom
    start = clock();
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            double re = -2.0 + (x / (double)width) * 3.0;
            double im = -1.5 + (y / (double)height) * 3.0;
            gen_mandelbrot(re, im);  // Call mandelbrot with complex numbers
        }
    }
    end = clock();
    double time_custom = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for Mandelbrot with custom: %.6f seconds\n", time_custom);
    
}

int main()
{
    test_mandelbrot();  // Run the test for Mandelbrot iterations
    return 0;
}

