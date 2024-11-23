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

int main() {
    int size = 10;
    int* arr = new int[size] {20, 1, 45, 432, 78, 900, 89435, 22, 45, 11};

    countSortUnstable(arr, size);

    printArray(arr, size);

    return 0;
}