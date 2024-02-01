//Write a program to compute nth Fibonacci number recursively and analyze its 
//time efficiency

#include <stdio.h>
#include <time.h>

int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}

int main() {
    int n, result;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);

    clock_t start_time = clock();

    result = fibonacciRecursive(n);

    clock_t end_time = clock();

    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("The %dth Fibonacci number is: %d\n", n, result);
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
