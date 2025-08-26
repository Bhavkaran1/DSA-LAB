#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int tri[10] = {1,2,3,4,  // main diagonal
                   5,6,7,    // upper
                   8,9,10};  // lower

    int k=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i==j) cout << tri[i] << " ";
            else if (i==j-1) cout << tri[n+i] << " ";
            else if (i==j+1) cout << tri[2*n+i-1] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
