#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int lower[6] = {1,2,3,4,5,6}; // packed row-wise

    int k=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (j<=i) cout << lower[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
