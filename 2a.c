//User Write a program to find GCD using consecutive integer checking method and
//analyze its time efficiency in c

#include <stdio.h>
#include <time.h>

int findGCD(int a, int b) {
    int gcd = 1;
    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

int main() {
    int num1, num2, gcd;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    clock_t start_time = clock();

    gcd = findGCD(num1, num2);

    clock_t end_time = clock();

    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("GCD of %d and %d using consecutive integer checking method is: %d\n", num1, num2, gcd);
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
