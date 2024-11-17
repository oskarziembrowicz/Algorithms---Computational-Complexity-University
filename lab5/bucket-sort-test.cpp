#include <iostream>
#include <vector>

using namespace std;

const int N_OF_LETTERS = int('Z')-int('A')+1;

struct Noble {
    char initial;
    Noble(char initial) {
        this->initial = initial;
    }
};

int charToAsciiArr(char c) {
    return int(c) - 65;
}

// void insertionSort(vector<int>& bucket) {
//     for (int i = 1; i < bucket.size(); ++i) {
//         float key = bucket[i];
//         int j = i - 1;
//         while (j >= 0 && bucket[j] > key) {
//             bucket[j + 1] = bucket[j];
//             j--;
//         }
//         bucket[j + 1] = key;
//     }
// }

// void bucketSort(vector<char>& arr) {
//     // const int n = arr.size();
//     // 1) Create n empty buckets
//     vector<vector<char>> b(N_OF_LETTERS);

//     // BUCKETS ARE OUT OF ORDER

//     // 2) Put array elements in different buckets
//     for (int i = 0; i < arr.size(); i++) {
//         // int tmp = turnToSmall(arr[i]) * n;
//         // b[tmp].push_back(arr[i]);

//         int tmp = charToAsciiArr(arr[i]);
//         b[tmp].push_back(arr[i]);

//         // int bi = n * turnToSmall([i]);
//         // b[bi].push_back(arr[i]);
//     }

//     // THIS IS OK:
//     for (int i=0; i<N_OF_LETTERS; i++) {
//         cout << i << ": ";
//         for (int j = 0; j < b[i].size(); j++) {
//             cout << b[i][j] << " ";
//         }
//         cout << "\n";
//     }
//     cout << "\n";

//     // 3) Sort individual buckets using insertion sort
//     for (int i = 0; i < n; i++) {
//         insertionSort(b[i]);
//     }

//     // 4) Concatenate all buckets into arr[]
//     int index = 0;
//     for (int i = 0; i < N_OF_LETTERS; i++) {
//         for (int j = 0; j < b[i].size(); j++) {
//             arr[index++] = b[i][j];
//             cout << arr[index-1] << "\n";
//         }
//     }
//     cout << arr.size() << "\n";
//     cout << "checkpoint 1\n";
//     return;
// }

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

int main() {
    // vector<int> numbers = {915, 960, 152, 514, 1325, 900, 1452, 637, 1085, 1282};
    vector<char> initials = {'X', 'Z', 'X', 'F', 'E'};
    vector<Noble> nobles = {Noble('X'), Noble('Z'), Noble('X'), Noble('F'), Noble('E')};

    bucketSortNobles(nobles);

    for (Noble n : nobles) {
        cout << n.initial << " ";
    }
    cout << "\n";

    return 0;
}