#include <iostream>

using namespace std;

void printArray(int* arr, int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void mergeSort(int* arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    // Merging
    int leftSize = mid+1-start;
    int rightSize = end-mid;
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];
    
    for (int i=0; i<leftSize; i++) {
        leftArr[i] = arr[start+i];
    }
    for (int i=0; i<rightSize; i++) {
        rightArr[i] = arr[mid+1+i];
    }

    int leftIter = 0, rightIter = 0, mainIter = start;

    while (leftIter < leftSize && rightIter < rightSize) {
        if (leftArr[leftIter] <= rightArr[rightIter]) {
            arr[mainIter++] = leftArr[leftIter++];
        } else {
            arr[mainIter++] = rightArr[rightIter++];
        }
    }

    while (leftIter < leftSize) {
        arr[mainIter++] = leftArr[leftIter++];
    }
    while (rightIter < rightSize) {
        arr[mainIter++] = rightArr[rightIter++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

int main() {
    int size = 10;
    int* arr = new int[size] {20, 1, 45, 432, 78, 900, 89435, 22, 45, 11};

    mergeSort(arr, 0, size-1);

    printArray(arr, size);

    delete[] arr;

    return 0;
}