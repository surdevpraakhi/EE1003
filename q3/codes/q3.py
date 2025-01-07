import ctypes
import numpy as np
import matplotlib.pyplot as plt

# Load the shared object file
trapezoidal = ctypes.CDLL('./q3.so')

# Set argument and return types for the compute_total_area function
trapezoidal.compute_total_area.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_int]
trapezoidal.compute_total_area.restype = ctypes.c_double

# Define parameters
a = 2.0  # Start of the interval for y
b = 4.0  # End of the interval for y
n = 1000  # Number of trapezoids

# Call the compute_total_area function from the C library
total_area = trapezoidal.compute_total_area(a, b, n)

# Print the total area
print(f"Total area (sim): {total_area}")

# Plotting the curve x^2 = 4y
y = np.linspace(a, b, 500)  # Generate y values
x = 2 * np.sqrt(y)          # Calculate corresponding x values for the curve

# Create the plot
plt.figure(figsize=(8, 6))

# Plot the curve
plt.plot(x, y, label=r"$x^2 = 4y$", color="blue", linewidth=2)

# Highlight the lines y = 4 and y = 2
plt.axhline(y=4, color="red", linestyle="--", label=r"$y = 4$")
plt.axhline(y=2, color="green", linestyle="--", label=r"$y = 2$")

# Fill the shaded region between the curve and y=4
plt.fill_betweenx(y, 0, x, where=(y >= 2), color="lightblue", alpha=0.5)

plt.xlabel("x", fontsize=12)
plt.ylabel("y", fontsize=12)
plt.legend(fontsize=12)

# Add the area annotation at the top-right corner
plt.text(
    2.5, 4.1,  # Position: slightly above the top-right corner of the curve
    f"sim Area = {total_area:.4f}", 
    fontsize=12, 
    color="black", 
    ha="right", 
    bbox=dict(facecolor='white', alpha=0.8)
)

# Display the plot
plt.grid(True)
plt.show()

