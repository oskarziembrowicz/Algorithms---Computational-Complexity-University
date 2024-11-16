#include <iostream>
#include <vector>

using namespace std;

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

void mergeSortNobles(vector<Noble>& vec, int start, int end) {
    if (start >= end) {
        return;
    }

    // Calculating the mid element index
    int mid = start + (end-start)/2;
    mergeSortNobles(vec, start, mid);
    mergeSortNobles(vec, mid+1, end);
    
    // -------
    // Merging
    //--------

    // Creating temp vectors
    int l_size = mid + 1 - start;
    int r_size = end - mid;
    vector<Noble> left(l_size), right(r_size);

    for (int i=0; i<l_size; i++) {
        left[i] = vec[start+i];
    }
    for (int i=0; i<r_size; i++) {
        right[i] = vec[mid+1+i];
    }

    int l_iter = 0, r_iter = 0, v_iter = start;

    // Merge vectors
    while(l_iter < l_size && r_iter < r_size) {
        if (left[l_iter].initial <= right[r_iter].initial) {
            vec[v_iter] = left[l_iter++];
        } else {
            vec[v_iter] = right[r_iter++];
        }
        v_iter++;
    }

    // Merge the rest
    while (l_iter < l_size) {
        vec[v_iter++] = left[l_iter++];
    }
    while (r_iter < r_size) {
        vec[v_iter++] = right[r_iter++];
    }
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

void insertionSort(vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(vector<float>& arr, int n) {
    const int n = arr.size();
    // 1) Create n empty buckets
    vector<vector<float>> b(n);

    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++) {
        insertionSort(b[i]);
    }

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
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
    mergeSortNobles(nobles, 0, nobles.size()-1);

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