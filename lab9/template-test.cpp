#include <iostream>

using namespace std;

template <typename T>
class Array {
public:
    T array[10];

    void fill(T value) {
        for (int i=0; i<10; i++) {
            array[i] = value;
        }
    }

    &T at(int i) {
        return array[i];
    }
};

int main() {
    

    return 0;
}