#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int sym[6] = {1,2,3,4,5,6}; // store lower triangle

    int k=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (j<=i) cout << sym[k++] << " ";
            else cout << sym[j*(j+1)/2 + i] << " "; // mirror
        }
        cout << endl;
    }
    return 0;
}
