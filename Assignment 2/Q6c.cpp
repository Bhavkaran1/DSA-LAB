// Multiplication of two sparse matrices

#include <iostream>
using namespace std;

void multiply(int A[10][3], int B[10][3], int C[20][3]) {
    if(A[0][1] != B[0][0]) {
        cout << "Multiplication not possible\n";
        return;
    }

    C[0][0] = A[0][0];
    C[0][1] = B[0][1];
    int k = 1;

    for(int i = 1; i <= A[0][2]; i++) {
        for(int j = 1; j <= B[0][2]; j++) {
            if(A[i][1] == B[j][0]) {
                int r = A[i][0];
                int c = B[j][1];
                int v = A[i][2] * B[j][2];

                int found = 0;
                for(int x = 1; x < k; x++) {
                    if(C[x][0] == r && C[x][1] == c) {
                        C[x][2] += v;
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    C[k][0] = r;
                    C[k][1] = c;
                    C[k][2] = v;
                    k++;
                }
            }
        }
    }

    C[0][2] = k-1;
}

void print(int A[20][3]) {
    cout << "\nRow    Col    Value\n";
    for(int i = 0; i <= A[0][2]; i++) {
        cout << A[i][0] << "       " << A[i][1] << "      " << A[i][2] << endl;
    }
}

int main() {
    int A[10][3] = {
        {2, 3, 2},   // 2x3, 2 non-zero
        {0, 0, 2},
        {1, 2, 3}
    };

    int B[10][3] = {
        {3, 2, 2},   // 3x2, 2 non-zero
        {0, 1, 4},
        {2, 0, 5}
    };

    int C[20][3];
    multiply(A, B, C);

    cout << "Matrix A :\n"; print(A);
    cout << "\nMatrix B :\n"; print(B);
    cout << "\nProduct :\n"; print(C);
}
