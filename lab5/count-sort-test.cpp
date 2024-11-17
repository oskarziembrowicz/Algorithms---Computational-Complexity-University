#include <iostream>
#include <vector>

using namespace std;

vector<int> countSort(vector<int> inputVector) {
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

    // Calculate the prefix sum
    for(int i=1; i<maximum+1; i++) {
        countVector[i] += countVector[i-1];
    }

    // Create output vector
    vector<int> outputVector(size);

    // Update output vector
    for (int i=size-1; i>=0; i--) {
        outputVector[--countVector[inputVector[i]]] = inputVector[i];
    }

    return outputVector;
}

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
    vector<int> numbers = {915, 960, 152, 514, 1325, 900, 1452, 637, 1085, 1282};
    // numbers = countSort(numbers);
    countSortUnstable(numbers);

    for (int e : numbers) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}