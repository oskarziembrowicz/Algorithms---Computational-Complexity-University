#include <iostream>
#include <vector>
#include <algorithm> // JUST FOR TESTING

using namespace std;

// STILL A LITTLE TOO SLOW
// PROBLEM IN SORTING PEASANTS

const int N_OF_LETTERS = int('Z')-int('A')+1;

struct Noble {
    char initial;
    int number_of_peasants;
    vector<int> peasants;
};

/*
ALGORITHMS
- count sort -- very close (memory?)
- bucket sort -- best for nobles
- quick sort -- too slow + memory
- merge sort -- quite close + memory
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

// void quickSort(vector<int>& vec, int start, int end) {
//     if (start >= end) {
//         // There are less than 2 elements
//         return;
//     }

//     int pivot = vec[end];
//     // Set swapping index
//     int swapIter = start - 1;

//     for (int j=start; j<end; j++) {
//         if (vec[j] < pivot) {
//             swap(vec[++swapIter], vec[j]);
//         }
//     }
//     // Move pivot (vec[end]) to its correct position
//     swap(vec[end], vec[++swapIter]);

//     // Now call quickSort for subvectors
//     quickSort(vec, start, swapIter-1);
//     quickSort(vec, swapIter+1, end);
// }

// void insertionSort(vector<int>& bucket) {
//     for (int i = 1; i < bucket.size(); ++i) {
//         int key = bucket[i];
//         int j = i - 1;
//         while (j >= 0 && bucket[j] > key) {
//             bucket[j + 1] = bucket[j];
//             j--;
//         }
//         bucket[j + 1] = key;
//     }
// }

// int numDigits(int number)
// {
//     int digits = 0;
//     if (number < 0) digits = 1;
//     while (number) {
//         number /= 10;
//         digits++;
//     }
//     return digits;
// }

// // Function to sort arr[] of size n using bucket sort
// void bucketSort(vector<int> arr) {
//     int n = arr.size();

//     // 1) Create n empty buckets
//     vector<vector<int>> b(6);

//     // 2) Put array elements in different buckets
//     for (int i = 0; i < n; i++) {
//         int bi = numDigits(arr[i]);
//         b[bi].push_back(arr[i]);
//     }

//     // 3) Sort individual buckets using insertion sort
//     for (int i = 0; i < n; i++) {
//         insertionSort(b[i]);
//     }

//     // 4) Concatenate all buckets into arr[]
//     int index = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < b[i].size(); j++) {
//             arr[index++] = b[i][j];
//             cout << arr[index-1] << " ";
//         }
//         cout << "\n";
//     }
// }

void countSortUnstable(vector<int>& inputVector) {
    int size = inputVector.size();
    int maximum = 0;

    // Calculate maximum from input vector
    for(int i=0; i<size; i++) {
        maximum = max(inputVector[i], maximum);
    }

    // Initiate count vector of size maximum+1 with zeros
    vector<int> countVector(maximum+1, 0);

    // Update count vector
    for (int i=0; i<size; i++) {
        countVector[inputVector[i]]++;
    }

    // Add elements to input vector in order
    int index = 0;
    for (int i=0; i<maximum+1; i++) {
        while (countVector[i]-- > 0) {
            inputVector[index++] = i;
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
        // quickSort(nobles[i].peasants, 0, nobles[i].peasants.size()-1);
        // nobles[i].peasants = countSort(nobles[i].peasants);
        // mergeSort(nobles[i].peasants, 0, nobles[i].peasants.size()-1);
        countSortUnstable(nobles[i].peasants);
        // bucketSort(nobles[i].peasants);
    }

    // ======================================
    // ======================================
    // --------------
    // Sorting nobles
    //---------------

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