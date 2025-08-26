// Addition of two sparse matrices 

#include <iostream>
using namespace std;

void add_sparse(int A[10][3], int B[10][3], int C[20][3]) {
    if(A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Addition not possible\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while(i <= A[0][2] && j <= B[0][2]) {
        if(A[i][0] < B[j][0] || (A[i][0]==B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if(B[j][0] < A[i][0] || (A[i][0]==B[j][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
    }

    while(i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }
    while(j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
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
        {3, 3, 3},
        {0, 0, 5},
        {1, 1, 8},
        {2, 2, 6}
    };

    int B[10][3] = {
        {3, 3, 2},
        {0, 0, 3},
        {1, 2, 4}
    };

    int C[20][3];
    add_sparse(A, B, C);

    cout << "Matrix A :\n"; print(A);
    cout << "\nMatrix B :\n"; print(B);
    cout << "\nSum :\n"; print(C);
}
