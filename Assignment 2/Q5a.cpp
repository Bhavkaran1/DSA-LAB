#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int diag[4] = {1, 2, 3, 4};

    // print full matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << diag[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
