#include <stdio.h>
#include <time.h>

void function1() {
    for (volatile int i = 0; i < 100000000; i++); // Simulate work
}

void function2() {
    for (volatile int i = 0; i < 200000000; i++); // Simulate work
}

int main() {
    clock_t start, end;
    double time_spent;

    start = clock();
    function1();
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time of function1: %f seconds\n", time_spent);

    start = clock();
    function2();
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time of function2: %f seconds\n", time_spent);

    return 0;
}
