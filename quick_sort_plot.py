import matplotlib.pyplot as plt
import pandas as pd

# Load data
data = pd.read_csv('quicksort_times.csv')

# Plot graph
plt.plot(data['Array Size'], data['Time (microseconds)'], label='QuickSort')

# Labels and title
plt.xlabel('Array Size')
plt.ylabel('Time (microseconds)')
plt.title('QuickSort Time Complexity')
plt.legend()

# Show plot
plt.show()
