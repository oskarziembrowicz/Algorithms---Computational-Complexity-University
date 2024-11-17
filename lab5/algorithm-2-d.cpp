#include <iostream>
#include <vector>

using namespace std;

// STILL A TINY BIT TOO SLOW

const int N_OF_LETTERS = int('Z')-int('A')+1;

struct Noble {
    char initial;
    int number_of_peasants;
    int *peasants;
};

int charToAsciiArr(char c) {
    return int(c) - 65;
}

void bucketSortNobles(Noble* arr, int size) {
    // Create empty buckets
    vector<Noble>* buckets = new vector<Noble>[N_OF_LETTERS];

    // Put vector elements in different buckets based on ascii
    for (int i = 0; i < size; i++) {
        buckets[charToAsciiArr(arr[i].initial)].push_back(arr[i]);
    }

    // Concatenate all buckets into vec
    int index = 0;
    for (int i = 0; i < N_OF_LETTERS; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
    
    delete[] buckets;
}

void countSortUnstable(int* inputArray, int size) {
    int maximum = 0;

    // Calculate maximum from input vector
    for(int i=0; i<size; i++) {
        maximum = max(inputArray[i], maximum);
    }

    // Initiate count vector of size maximum+1 with zeros
    int* countVector = new int[maximum+1] ();

    // Update count vector
    for (int i=0; i<size; i++) {
        countVector[inputArray[i]]++;
    }

    // Add elements to input vector in order
    int index = 0;
    for (int i=0; i<maximum+1; i++) {
        while (countVector[i]-- > 0) {
            inputArray[index++] = i;
        }
    } 

    delete[] countVector;
}

int main() {
    // ======================================
    // -------------
    // Input section
    // -------------

    int numberOfNobles;
    // cout << "Enter number of nobles: ";
    cin >> numberOfNobles;
    Noble* nobles = new Noble[numberOfNobles];

    for (int i=0; i<numberOfNobles; i++ ) {
        // cout << "Enter initial of the noble and number of his pesants: ";
        cin >> nobles[i].initial >> nobles[i].number_of_peasants;
        nobles[i].peasants = new int[nobles[i].number_of_peasants];
        for (int j=0; j<nobles[i].number_of_peasants; j++) {
            int peasant;
            // cout << "Enter peasant code: ";
            cin >> nobles[i].peasants[j];
        }
        // ==================================
        // -----------------
        // Sort the peasants
        // -----------------
        countSortUnstable(nobles[i].peasants, nobles[i].number_of_peasants);
        // ==================================
    }

    // ======================================
    // --------------
    // Sorting nobles
    //---------------

    bucketSortNobles(nobles, numberOfNobles);

    // ======================================
    // --------------
    // Output section
    // --------------

    for (int i=0; i<numberOfNobles; i++) {
        cout << nobles[i].initial << ": ";
        for (int j=0; j<nobles[i].number_of_peasants; j++) {
            cout << nobles[i].peasants[j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    // ======================================

    // ======================================
    // ---------------------
    // Deleting dynamic data
    // ---------------------

    for (int i=0; i<numberOfNobles; i++) {
        delete[] nobles[i].peasants;
    }
    delete[] nobles;

    // ======================================
    
    return 0;
}