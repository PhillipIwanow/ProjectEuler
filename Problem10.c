#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to calculate the sum of all primes below a given limit using the Sieve of Eratosthenes
unsigned long sum_primes_below(unsigned long limit) {
    bool *is_prime = (bool *)malloc(limit * sizeof(bool));
    for (unsigned long i = 2; i < limit; i++) {
        is_prime[i] = true;
    }

    for (unsigned long p = 2; p * p < limit; p++) {
        if (is_prime[p]) {
            for (unsigned long multiple = p * p; multiple < limit; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    unsigned long sum = 0;
    for (unsigned long n = 2; n < limit; n++) {
        if (is_prime[n]) {
            sum += n;
        }
    }

    free(is_prime);
    return sum;
}

int main() {
    unsigned long limit = 2000000;
    unsigned long sum = sum_primes_below(limit);
    printf("The sum of all primes below %lu is %lu\n", limit, sum);
    return 0;
}