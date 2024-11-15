#include <iostream>
#include <vector>

using namespace std;

// TAKES TOO LONG

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

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> merged;

    int l_iter = 0;
    int r_iter = 0;

    // Merging two vectors
    while (l_iter < left.size() && r_iter < right.size()) {
        if (left[l_iter] <= right[r_iter]) {
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

vector<int> mergeSort(vector<int> vec, int start, int end) {
    if (start == end) {
        vector<int> single = {vec[start]};
        return single;
    }

    int mid = (start + end) / 2;
    vector<int> left = mergeSort(vec, start, mid);
    vector<int> right = mergeSort(vec, mid+1, end);

    return merge(left, right);
}

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


int main() {
    // n - liczba szlachciców
    // s - inicjał szlachcica
    // i - liczba chłopów w majątku szlachcica
    // k - kody chłopów (i-chłopów)
    int number_of_nobles;

    // Input section

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

    // Sorting peasants

    for (int i=0; i<nobles.size(); i++) {
        nobles[i].peasants = mergeSort(nobles[i].peasants, 0, nobles[i].peasants.size()-1);
    }

    // Sorting nobles

    nobles = mergeSortNobles(nobles, 0, nobles.size()-1);

    // Output section

    for (int i=0; i<nobles.size(); i++) {
        cout << nobles[i].initial << ": ";
        for (int j=0; j<nobles[i].peasants.size(); j++) {
            cout << nobles[i].peasants[j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}