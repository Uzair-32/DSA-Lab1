#include <iostream>
#include "task7source.h"
using namespace std;


void multiplyNaive(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n);
void multiplyStrassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n);

void printMatrix(int M[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

void runTest(int A[MAX][MAX], int B[MAX][MAX], int n) {
    int resultNaive[MAX][MAX] = {0};
    int resultStrassen[MAX][MAX] = {0};

    multiplyNaive(A, B, resultNaive, n);
    multiplyStrassen(A, B, resultStrassen, n);

    cout << "Naive Result:" << endl;
    printMatrix(resultNaive, n);
    cout << "Strassen Result:" << endl;
    printMatrix(resultStrassen, n);
    cout << endl;
}

int main() {
    // 2x2 test
    int A2[MAX][MAX] = {{1, 2}, {3, 4}};
    int B2[MAX][MAX] = {{5, 6}, {7, 8}};
    cout << "Test Case: 2x2" << endl;
    runTest(A2, B2, 2);

    // 4x4 test
    int A4[MAX][MAX] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int B4[MAX][MAX] = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    cout << "Test Case: 4x4" << endl;
    runTest(A4, B4, 4);

    // Random 4x4 test
    int AR[MAX][MAX] = {
        {2, 1, 3, 4},
        {0, 6, 7, 2},
        {5, 9, 8, 1},
        {4, 3, 2, 6}
    };
    int BR[MAX][MAX] = {
        {1, 0, 5, 2},
        {3, 7, 4, 1},
        {6, 8, 9, 0},
        {2, 4, 3, 5}
    };
    cout << "Test Case: Random 4x4" << endl;
    runTest(AR, BR, 4);

    return 0;
}
