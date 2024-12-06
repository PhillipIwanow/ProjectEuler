// Solution to Problem 14
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to compute the next number in the Collatz sequence
unsigned long NextCollatzNum(unsigned long num) {
    if ((num & 1) == 0) { // Check if the number is even using bitwise AND
        num >>= 1; // Effectively divide the number by two by shifting to the right
    } else {
        num = 3 * num + 1; // If the number is odd, multiply by 3 and add 1
    }
    return num;
}

// Function to compute the length of the Collatz sequence starting from 'start'
unsigned long CollatzSequenceLength(unsigned long start, unsigned long* cache) {
    // Check if the length has already been computed and cached
    if (start < 1000000 && cache[start] != 0) {
        return cache[start];
    }

    unsigned long length;
    if (start == 1) {
        length = 1; // Base case: the sequence length for 1 is 1
    } else {
        // Recursive case: 1 + length of the sequence for the next number
        length = 1 + CollatzSequenceLength(NextCollatzNum(start), cache);
    }

    // Cache the computed length for future use
    if (start < 1000000) {
        cache[start] = length;
    }

    return length;
}

int main() {
    unsigned long max_length = 0; // Variable to store the maximum sequence length found
    unsigned long max_start = 0;  // Variable to store the starting number that produces the longest sequence
    const unsigned long limit = 1000000; // The upper limit for starting numbers
    // Allocate memory for the cache and initialize it to zero
    unsigned long* cache = (unsigned long*)calloc(limit, sizeof(unsigned long));

    // Iterate over all starting numbers from limit-1 down to 1
    for (unsigned long i = limit - 1; i > 0; i--) {
        // Compute the length of the Collatz sequence for the current starting number
        unsigned long length = CollatzSequenceLength(i, cache);
        // Update the maximum length and starting number if a longer sequence is found
        if (length > max_length) {
            max_length = length;
            max_start = i;
        }
    }
