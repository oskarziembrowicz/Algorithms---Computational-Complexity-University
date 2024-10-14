#include <iostream>
#include <cmath>

using namespace std;
// ios_base::sync_with_stdio(false);

int main() {
    // int p;
    // scanf("%d", &p);
    // for (int i = 0; i < p; i++) {
    //     // Expression
    //     long int expression_value[] = {0, 0};
    //     // Here will be two descrioptions for expression
    //     for (int j=0; j<2; j++) {
    //         int n;
    //         scanf("%d", &n);
    //         for (int k = 0; k < n; k++) {
    //             int z;
    //             long int a;
    //             scanf("%d %d", &z, &a);
    //             if (z == 0) {
    //                 expression_value[j] += a;
    //             } else if (z == 1) {
    //                 expression_value[j] *= a;
    //             }
    //             printf("%d\n", expression_value[j]);
    //         }
    //     }
    //     if (expression_value[0] == expression_value[1]) {
    //         cout << "rowne\n";
    //     } else {
    //         cout << "rozne\n";
    //     }
    // } 

    // Chińskie twierdzenie o resztach

    long long int mod = pow(2, 30);
    long long int a = 32768;
    long long int b = a;
    for (int i = 0; i < 3; i++) {
        b = b % mod;
        b *= a % mod;
        cout << b << "\n";
    }

    return 0;
}

