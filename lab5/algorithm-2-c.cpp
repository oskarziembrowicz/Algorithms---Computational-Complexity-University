#include <iostream>
#include <vector>
#include <algorithm> // JUST FOR TESTING

using namespace std;

// STILL A LITTLE TOO SLOW (not changed)
// PROBLEM IN SORTING PEASANTS

const int N_OF_LETTERS = int('Z')-int('A')+1;

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

int charToAsciiArr(char c) {
    return int(c) - 65;
}

void bucketSortNobles(vector<Noble>& vec) {
    // Create empty buckets
    vector<vector<Noble>> buckets(N_OF_LETTERS);

    // Put vector elements in different buckets based on ascii
    for (int i = 0; i < vec.size(); i++) {
        int charIndex = charToAsciiArr(vec[i].initial);
        buckets[charIndex].push_back(vec[i]);
    }

    // Concatenate all buckets into vec
    int index = 0;
    for (int i = 0; i < N_OF_LETTERS; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            vec[index++] = buckets[i][j];
        }
    }
    return;
}

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
        // quickSort(nobles[i].peasants, 0, nobles[i].peasants.size()-1);
        // TEST:
        sort(nobles[i].peasants.begin(), nobles[i].peasants.end());
    }
    // ======================================
    // ======================================
    // --------------
    // Sorting nobles
    //---------------

    // nobles = mergeSortNobles(nobles, 0, nobles.size()-1);
    // mergeSortNobles(nobles, 0, nobles.size()-1);
    bucketSortNobles(nobles);

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