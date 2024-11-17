#include <iostream>
#include <vector>

using namespace std;

void quickSort(int* arr, int start, int end) {
    if (start >= end) {
        // There are less than 2 elements
        return;
    }

    int pivot = arr[end];
    // Set swapping index
    int swapIter = start - 1;

    for (int j=start; j<end; j++) {
        if (arr[j] < pivot) {
            swap(arr[++swapIter], arr[j]);
        }
    }
    // Move pivot (arr[end]) to its correct position
    swap(arr[end], arr[++swapIter]);

    // Now call quickSort for subarrays
    quickSort(arr, start, swapIter-1);
    quickSort(arr, swapIter+1, end);
}

int main() {
    int size = 7;
    int* numbers = new int[size] {671, 1564, 52, 1861, 681, 295, 721};
    quickSort(numbers, 0, size-1);
    for (int i=0; i<size; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n";

    return 0;
}