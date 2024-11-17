#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec) {
    for(int e : vec) {
        cout << e << " ";
    }
    cout << "\n";
}

void mergeSort(int* arr, int start, int end) {
    if (start >= end) {
        return;
    }

    // Calculating the mid element index
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    
    // -------
    // Merging
    //--------

    // Creating temp arrays
    int l_size = mid + 1 - start;
    int r_size = end - mid;
    int* left = new int[l_size];
    int* right = new int[r_size];

    for (int i=0; i<l_size; i++) {
        left[i] = arr[start+i];
    }
    for (int i=0; i<r_size; i++) {
        right[i] = arr[mid+1+i];
    }

    int l_iter = 0, r_iter = 0, v_iter = start;

    // Merge arrays
    while(l_iter < l_size && r_iter < r_size) {
        if (left[l_iter] <= right[r_iter]) {
            arr[v_iter] = left[l_iter++];
        } else {
            arr[v_iter] = right[r_iter++];
        }
        v_iter++;
    }

    // Merge the rest
    while (l_iter < l_size) {
        arr[v_iter++] = left[l_iter++];
    }
    while (r_iter < r_size) {
        arr[v_iter++] = right[r_iter++];
    }
    
    delete[] left;
    delete[] right;
}

int main() {
    int size = 10;
    int* numbers = new int[size] {915, 960, 152, 514, 1325, 900, 1452, 637, 1085, 1282};
    mergeSort(numbers, 0, size-1);
    for (int i=0; i<size; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n";
    return 0;
}