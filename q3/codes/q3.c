#include <stdio.h>
#include <math.h>

// Function to calculate x = 2 * sqrt(y) based on x^2 = 4y
double curve_function(double y) {
    return 2 * sqrt(y);
}

// Function to calculate the total area under the curve using the trapezoidal rule
__attribute__((visibility("default")))
__attribute__((used))
double compute_total_area(double a, double b, int n) {
    double h = (b - a) / n;  // Step size
    double total_area = 0.0;

    // Calculate the total area using the trapezoidal rule
    for (int i = 0; i < n; i++) {
        double y1 = a + i * h;
        double y2 = a + (i + 1) * h;
        double x1 = curve_function(y1);
        double x2 = curve_function(y2);
        total_area += (x1 + x2) * h / 2.0;  // Add area of each trapezoid
    }

    return total_area;
}

int main() {
    double a = 2.0;  // Lower limit for y
    double b = 4.0;  // Upper limit for y
    int n = 1000;    // Number of intervals

    // Compute the total area under the curve
    double area = compute_total_area(a, b, n);

    // Print the result
    printf("The total area under the curve x^2 = 4y is: %.6f\n", area);

    return 0;
}

