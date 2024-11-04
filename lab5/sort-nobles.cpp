#include <iostream>
#include <vector>

using namespace std;

struct Noble {
    char initial;
    Noble(char initial) {
        this->initial = initial;
    }
};

void printVector(vector<int> vec) {
    for(int e : vec) {
        cout << e << " ";
    }
    cout << "\n";
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
    vector<Noble> nobles = {Noble('X'), Noble('Z'), Noble('X'), Noble('F'), Noble('E')};
    for (Noble e : mergeSortNobles(nobles, 0, nobles.size()-1)) {
        cout << e.initial << " ";
    }
    cout << "\n";
    return 0;
}