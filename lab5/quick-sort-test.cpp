#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
  
    // Choose the pivot
    int pivot = arr[high];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[;ow..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSort1(vector<int>& vec, int start, int end) {
    if (start >= end) {
        // There are less than 2 elements
        return;
    }

    int size = vec.size();

    int pivot = vec[end];
    for (int i=0; i<size; i++) {
        if (vec[i] > pivot) {

        }
    }
}

int main() {
    vector<int> numbers = {915, 960, 152, 514, 1325, 900, 1452, 637, 1085, 1282};
    quickSort(numbers, 0, numbers.size()-1);
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << "\n";

    return 0;
}