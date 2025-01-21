import ctypes
import numpy as np
import matplotlib.pyplot as plt

# Load the shared library
dice_simulation = ctypes.CDLL('./q7.so')  # Ensure the correct shared library name

# Define the function prototype for get_cdf
# The function takes an integer (trials) and a pointer to a double array (output_probs)
dice_simulation.get_cdf.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_double)]

# Parameters
trials = 100000  # Number of simulations
output_probs = (ctypes.c_double * 13)()  # Probabilities for sums 2 to 12

# Call the C function
dice_simulation.get_cdf(trials, output_probs)

# Convert probabilities to a Python list (consider sums from 2 to 12)
probs = list(output_probs)[2:]  # Only consider sums from 2 to 12

# Define outcomes: 2 to 12
x_labels = ['2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12']

# Plot the probabilities
x = np.arange(len(x_labels))
plt.stem(x, probs, basefmt=" ", use_line_collection=True)
plt.xticks(x, x_labels)
plt.xlabel("Sum")
plt.ylabel("Probability")
plt.title("Probability of Sum of Coin and Die")
plt.grid()
plt.show()

