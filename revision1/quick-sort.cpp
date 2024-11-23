#include <iostream>

using namespace std;

void printArray(int* arr, int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void quickSort(int* arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = arr[end];
    int swapIndex = start-1;

    for (int i=start; i<end; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[++swapIndex]);
        }
    }
    swap(arr[end], arr[++swapIndex]);
    quickSort(arr, start, swapIndex-1);
    quickSort(arr, swapIndex+1, end);
}

int main() {
    int size = 10;
    int* arr = new int[size] {20, 1, 45, 432, 78, 900, 89435, 22, 45, 11};

    quickSort(arr, 0, size-1);
    printArray(arr, size);

    return 0;
}