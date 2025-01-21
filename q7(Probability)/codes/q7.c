#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the probabilities
void calculate_probabilities(int trials, double *probs) {
    int counts[13] = {0}; // Possible sums range from 2 to 12
    int coin, die, sum, i;

    // Seed the random number generator
    srand(time(NULL));

    // Simulate trials
    for (i = 0; i < trials; i++) {
        // Simulate coin toss (1 or 6)
        coin = (rand() % 2 == 0) ? 1 : 6;

        // Simulate die roll (1 to 6)
        die = (rand() % 6) + 1;

        // Calculate sum
        sum = coin + die;

        // Increment count for the sum
        if (sum >= 2 && sum <= 12) {
            counts[sum]++;
        }
    }

    // Normalize probabilities
    for (i = 2; i <= 12; i++) {
        probs[i] = (double)counts[i] / trials;
    }
}

// Exported function for Python
__attribute__((visibility("default"))) 
__attribute__((used)) 
void get_cdf(int trials, double *output_probs) {
    // Calculate probabilities for sums 2 to 12
    calculate_probabilities(trials, output_probs);
}

