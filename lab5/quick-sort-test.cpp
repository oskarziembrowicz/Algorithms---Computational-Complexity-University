#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int> arr, int start, int end, int layer) {
    if (start < end) {
        // Set pivot point
        int pivot = arr[end];
        // cout << "Pivot: "  << pivot << "\n";
        // MAYBE DONT SUBTRACT 1?
        int before_index = (start-1);

        // Swap elements based on pivot
        for (int i=start; i<end; i++) {
            if (arr[i] <= pivot) {
                // PUSH THIS ATHER THE SWAP?
                before_index++;
                swap(arr[before_index], arr[i]);
                cout << "Swapped " << arr[before_index] << " and " << arr[i] << "\n";
                // cout << "Array now: \t";
                // for (int n : arr) {
                //     cout << n << ", ";
                // }
                // cout << "\n";
            }
        }

        // Set pivot in position
        int pivot_index = before_index+1;
        swap(arr[pivot_index], arr[end]);

        // Continue recursively on the two halves
        quickSort(arr, start, pivot_index - 1, layer+1);
        quickSort(arr, pivot_index + 1, end, layer+1);

        cout << "Array at the layer " << layer << ":\t";
        for (int n : arr) {
            cout << n << ", ";
        }
        cout << "\n";
    }
    return arr;
}

int main() {
    vector<int> numbers = {915, 960, 152, 514, 1325, 900, 1452, 637, 1085, 1282};
    quickSort(numbers, 0, numbers.size()-1, 0);
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << "\n";

    return 0;
}