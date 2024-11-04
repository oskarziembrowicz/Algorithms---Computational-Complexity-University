#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec) {
    for(int e : vec) {
        cout << e << " ";
    }
    cout << "\n";
}

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

int main() {
    vector<int> numbers = {915, 960, 152, 514, 1325, 900, 1452, 637, 1085, 1282};
    for (int e : mergeSort(numbers, 0, numbers.size()-1)) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}