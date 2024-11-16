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

void mergeSort(vector<int>& vec, int start, int end) {
    if (start >= end) {
        return;
    }

    // Calculating the mid element index
    int mid = start + (end-start)/2;
    mergeSort(vec, start, mid);
    mergeSort(vec, mid+1, end);
    
    // -------
    // Merging
    //--------

    // Creating temp vectors
    int l_size = mid + 1 - start;
    int r_size = end - mid;
    vector<int> left(l_size), right(r_size);

    for (int i=0; i<l_size; i++) {
        left[i] = vec[start+i];
    }
    for (int i=0; i<r_size; i++) {
        right[i] = vec[mid+1+i];
    }

    int l_iter = 0, r_iter = 0, v_iter = start;

    // Merge vectors
    while(l_iter < l_size && r_iter < r_size) {
        if (left[l_iter] <= right[r_iter]) {
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

int main() {
    vector<int> numbers = {915, 960, 152, 514, 1325, 900, 1452, 637, 1085, 1282};
    mergeSort(numbers, 0, numbers.size()-1);
    for (int e : numbers) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}