#include <iostream>
#include <vector>

using namespace std;

// A - 65
// Z - 90
const int N_OF_CHARS = 90-65;

int charToAsciiArr(char c) {
    return int(c) - 65;
}

void insertionSort(vector<int>& bucket) {
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

void bucketSortNobles(vector<char>& arr) {
    // const int n = arr.size();
    // 1) Create n empty buckets
    vector<vector<char>> b(N_OF_CHARS);

    // BUCKETS ARE OUT OF ORDER

    // 2) Put array elements in different buckets
    for (int i = 0; i < arr.size(); i++) {
        // int tmp = turnToSmall(arr[i]) * n;
        // b[tmp].push_back(arr[i]);

        int tmp = charToAsciiArr(arr[i]);
        b[tmp].push_back(arr[i]);

        // int bi = n * turnToSmall([i]);
        // b[bi].push_back(arr[i]);
    }

    // THIS IS OK:
    // for (int i=0; i<N_OF_CHARS; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < b[i].size(); j++) {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    // 3) Sort individual buckets using insertion sort
    // for (int i = 0; i < n; i++) {
    //     insertionSort(b[i]);
    // }

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < N_OF_CHARS; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
            cout << arr[index-1] << "\n";
        }
    }
    cout << arr.size() << "\n";
    cout << "checkpoint 1\n";
    return;
}

int main() {
    // vector<int> numbers = {915, 960, 152, 514, 1325, 900, 1452, 637, 1085, 1282};
    vector<char> initials = {'X', 'Z', 'X', 'F', 'E'};

    bucketSortNobles(initials);

    // CODE STOPS HERE WTF?!
    
    cout << "checkpoint 2\n";
    cout << initials.size();

    for (char e : initials) {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}