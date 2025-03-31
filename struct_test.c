#include <stdio.h>
#include <time.h>

#define ITERATIONS 100000000

// Define a struct with two doubles
typedef struct {
    double a;
    double b;
} DoubleStruct;

void benchmark_separate_doubles() {
    double x = 1.23, y = 4.56;
    volatile double sum = 0.0; // Prevent compiler optimizations

    clock_t start = clock();
    for (long i = 0; i < ITERATIONS; i++) {
        sum += x * y; // Simple multiplication and accumulation
    }
    clock_t end = clock();
    
    printf("Separate doubles time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void benchmark_struct_doubles() {
    DoubleStruct ds = {1.23, 4.56};
    volatile double sum = 0.0; // Prevent compiler optimizations

    clock_t start = clock();
    for (long i = 0; i < ITERATIONS; i++) {
        sum += ds.a * ds.b; // Access struct members and multiply
    }
    clock_t end = clock();
    
    printf("Struct doubles time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    printf("Benchmarking access times:\n");
    benchmark_separate_doubles();
    benchmark_struct_doubles();
    return 0;
}

