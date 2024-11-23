#include <iostream>

using namespace std;

void printArray(int* arr, int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int maximum(int* arr, int size) {
    int max = 0;
    for (int i=0; i<size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSortUnstable(int* arr, int size) {
    int max = maximum(arr, size);

    int* countArr = new int[max+1]();
    for (int i=0; i<size; i++) {
        countArr[arr[i]]++;
    }

    int iter = 0;
    for (int i=0; i<max+1; i++) {
        while (countArr[i]-- > 0) {
            arr[iter++] = i;
        }
    }
}

void prefixSum(int* arr, int size) {
    for (int i=1; i<size; i++) {
        arr[i] += arr[i-1];
    }
}

int* countSort(int* arr, int size) {
    int max = maximum(arr, size);

    int* countArr = new int[max+1]();
    for (int i=0; i<size; i++) {
        countArr[arr[i]]++;
    }

    prefixSum(countArr, max+1);

    int* outputArr = new int[size];

    for (int i=size-1; i>=0; i--) {
        outputArr[--countArr[arr[i]]] = arr[i];
    }

    delete[] countArr;
    return outputArr;
}

int main() {
    int size = 10;
    int* arr = new int[size] {20, 1, 45, 432, 78, 900, 89435, 22, 45, 11};

    arr = countSort(arr, size);

    printArray(arr, size);

    delete[] arr;

    return 0;
}