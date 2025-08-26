// Finding transpose of a sparse matrix


#include <iostream>
using namespace std;

void transpose(int A[10][3], int B[10][3]) {
    int len = A[0][2];   
    B[0][0] = A[0][1]; 
    B[0][1] = A[0][0];
    B[0][2] = len;

    int k = 1;
    for(int col = 0; col < A[0][1]; col++) {
        for(int i = 1; i <= len; i++) {
            if(A[i][1] == col) {
                B[k][0] = A[i][1];
                B[k][1] = A[i][0];
                B[k][2] = A[i][2];
                k++;
            }
        }
    }
}

void print(int A[10][3]) {
    cout << "\nRow    Col    Value\n";
    for(int i = 0; i <= A[0][2]; i++) {
        cout << A[i][0] << "       " << A[i][1] << "      " << A[i][2] << endl;
    }
}

int main() {
    int A[10][3] = {
        {3, 3, 4},   // 3x3 matrix with 4 non-zero elements
        {0, 0, 5},
        {1, 2, 8},
        {3, 1, 3},
        {2, 0, 6}
    };

    int B[10][3];
    transpose(A, B);

    cout << "Original :\n";
    print(A);
    cout << "\nTranspose :\n";
    print(B);
}
