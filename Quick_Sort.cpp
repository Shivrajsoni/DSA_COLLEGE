#include <iostream>
#include <chrono> // To measure time
#include <cstdlib> // For generating random numbers
#include <fstream> // To save results to a file

using namespace std;
using namespace std::chrono;

// QuickSort implementation
int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    
    while (i < j) {
        while (arr[i] <= pivot && i < high) i++;
        while (arr[j] > pivot) j--;
        
        if (i < j) swap(arr[i], arr[j]);
    }
    
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Function to generate random array
void generateRandomArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
}

int main() {
    ofstream outfile("quicksort_times.csv"); // To store results

    outfile << "Array Size,Time (microseconds)\n"; // CSV header

    for (int n = 1000; n <= 100000; n += 1000) { // Vary array size
        int *arr = new int[n];
        generateRandomArray(arr, n);

        // Measure time taken by QuickSort
        auto start = high_resolution_clock::now();
        quickSort(arr, 0, n - 1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();

        // Output size and time
        cout << "Array size: " << n << ", Time taken: " << duration << " microseconds" << endl;

        // Save to file
        outfile << n << "," << duration << "\n";

        delete[] arr; // Clean up memory
    }

    outfile.close();
    return 0;
}
