#include <iostream>
#include <vector>

using namespace std;

// THIS IS QUICKER BUT STILL A BIT TOO SLOW
// OUT OF MEMORY TOO

// NEW MERGE SORT SOLVES MEMORY PROBLEM
// STILL A LITTLE TOO SLOW

struct Noble {
    char initial;
    int number_of_peasants;
    vector<int> peasants;
};

/*
ALGORITHMS
- count sort (families)
- bucket sort
- quick sort
- count sort
- merge sort
*/

vector<Noble> mergeNobles(vector<Noble> left, vector<Noble> right) {
    vector<Noble> merged;

    int l_iter = 0;
    int r_iter = 0;

    // Merging two vectors
    while (l_iter < left.size() && r_iter < right.size()) {
        if (left[l_iter].initial <= right[r_iter].initial) {
            merged.push_back(left[l_iter++]);
        } else {
            merged.push_back(right[r_iter++]);
        }
    }

    // Adding the remaining elements
    if (l_iter == left.size()) {
        while (r_iter < right.size()) {
            merged.push_back(right[r_iter++]);
        }
    } else {
        while (l_iter < left.size()) {
            merged.push_back(left[l_iter++]);
        }
    }

    return merged;
}

void merge(vector<Noble>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<Noble> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i].initial <= R[j].initial) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<Noble>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

vector<Noble> mergeSortNobles(vector<Noble> vec, int start, int end) {
    if (start == end) {
        vector<Noble> single = {vec[start]};
        return single;
    }

    int mid = (start + end) / 2;
    vector<Noble> left = mergeSortNobles(vec, start, mid);
    vector<Noble> right = mergeSortNobles(vec, mid+1, end);

    return mergeNobles(left, right);
}

void quickSort(vector<int>& vec, int start, int end) {
    if (start >= end) {
        // There are less than 2 elements
        return;
    }

    int pivot = vec[end];
    // Set swapping index
    int swapIter = start - 1;

    for (int j=start; j<end; j++) {
        if (vec[j] < pivot) {
            swap(vec[++swapIter], vec[j]);
        }
    }
    // Move pivot (vec[end]) to its correct position
    swap(vec[end], vec[++swapIter]);

    // Now call quickSort for subvectors
    quickSort(vec, start, swapIter-1);
    quickSort(vec, swapIter+1, end);
}


int main() {
    // n - liczba szlachciców
    // s - inicjał szlachcica
    // i - liczba chłopów w majątku szlachcica
    // k - kody chłopów (i-chłopów)

    // ======================================
    // -------------
    // Input section
    // -------------

    int number_of_nobles;
    // cout << "Enter number of nobles: ";
    cin >> number_of_nobles;

    vector<Noble> nobles(number_of_nobles);

    for (int i=0; i<number_of_nobles; i++ ) {
        char noble_initial;
        int number_of_pesants;
        // cout << "Enter initial of the noble and number of his pesants: ";
        cin >> nobles[i].initial >> nobles[i].number_of_peasants;
        for (int j=0; j<nobles[i].number_of_peasants; j++) {
            int peasant;
            // cout << "Enter peasant code: ";
            cin >> peasant;
            nobles[i].peasants.push_back(peasant);
        }
    }
    // ======================================
    // ======================================
    // ----------------
    // Sorting peasants
    // ----------------

    for (int i=0; i<nobles.size(); i++) {
        quickSort(nobles[i].peasants, 0, nobles[i].peasants.size()-1);
    }
    // ======================================
    // ======================================
    // --------------
    // Sorting nobles
    //---------------

    // nobles = mergeSortNobles(nobles, 0, nobles.size()-1);
    mergeSort(nobles, 0, nobles.size()-1);

    // ======================================
    // ======================================
    // --------------
    // Output section
    // --------------

    for (int i=0; i<nobles.size(); i++) {
        cout << nobles[i].initial << ": ";
        for (int j=0; j<nobles[i].peasants.size(); j++) {
            cout << nobles[i].peasants[j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    // ======================================

    return 0;
}