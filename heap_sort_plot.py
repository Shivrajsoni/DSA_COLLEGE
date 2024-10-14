import matplotlib.pyplot as plt
import pandas as pd

# Load CSV data
data = pd.read_csv("heapsort_times.csv")

# Plot


if 'Array Size' in data.columns and 'Time (microseconds)' in data.columns:
    plt.plot(data['Array Size'], data['Time (microseconds)'], label="Heap Sort Time Complexity")
else:
    print("One or both of the columns 'Array Size' and 'Time in (microseconds)' do not exist in the DataFrame.")



plt.xlabel('Array Size')
plt.ylabel('Time in (microseconds)')
plt.title('Heap Sort Time Complexity')
plt.legend()
plt.grid(True)
plt.show()
