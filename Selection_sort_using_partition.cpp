// doing it further

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    // Loop through each element of the array
    for (int i = 0; i < n - 1; ++i) {
        // Assume the minimum element is at the current position i
        int minIndex = i;

        // Find the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
