#include <stdio.h>
#include <math.h>

int main(void) {
    // Initial guess
    double x = 40.0, xprev; // Start close to the expected solution
    int i = 0;

    // Print header for iterations
    printf("Iteration\t x_n\t\t Difference\n");

    // Newton's Method iteration
    do {
        xprev = x;
        // Update equation for Newton's method
        x = x - (pow(x, 2) - 8 * x - 1280) / (2 * x - 8);
        // Print current iteration, value, and difference
        printf("%d\t\t %.10lf\t %.10lf\n", i, x, fabs(x - xprev));
        i++;
    } while (fabs(x - xprev) >= 1e-6 && i < 1000); // Stop if difference is less than tolerance or max iterations reached

    // Check for convergence
    if (i >= 1000) {
        printf("Failed to converge within 1000 iterations.\n");
    } else {
        printf("Converged at iteration %d: x = %.10lf\n", i, x);
    }

    return 0;
}

