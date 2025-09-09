#include <iostream>
using namespace std;

const int MAX = 8; // max size for demo (works for 2x2, 4x4, 8x8)

// Naive multiplication
void multiplyNaive(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

// Add two matrices
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Subtract two matrices
void subtractMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen multiplication
void multiplyStrassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int a11[MAX][MAX], a12[MAX][MAX], a21[MAX][MAX], a22[MAX][MAX];
    int b11[MAX][MAX], b12[MAX][MAX], b21[MAX][MAX], b22[MAX][MAX];
    int p1[MAX][MAX], p2[MAX][MAX], p3[MAX][MAX], p4[MAX][MAX], p5[MAX][MAX], p6[MAX][MAX], p7[MAX][MAX];
    int temp1[MAX][MAX], temp2[MAX][MAX];

    // Split A and B into 4 submatrices each
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // using Strassen's formulas to calculate p1 to p7 because it has less multiplications
    // p1 = (a11+a22) * (b11+b22)
    addMatrix(a11, a22, temp1, newSize);
    addMatrix(b11, b22, temp2, newSize);
    multiplyStrassen(temp1, temp2, p1, newSize);

    // p2 = (a21+a22) * b11
    addMatrix(a21, a22, temp1, newSize);
    multiplyStrassen(temp1, b11, p2, newSize);

    // p3 = a11 * (b12-b22)
    subtractMatrix(b12, b22, temp1, newSize);
    multiplyStrassen(a11, temp1, p3, newSize);

    // p4 = a22 * (b21-b11)
    subtractMatrix(b21, b11, temp1, newSize);
    multiplyStrassen(a22, temp1, p4, newSize);

    // p5 = (a11+a12) * b22
    addMatrix(a11, a12, temp1, newSize);
    multiplyStrassen(temp1, b22, p5, newSize);

    // p6 = (a21-a11) * (b11+b12)
    subtractMatrix(a21, a11, temp1, newSize);
    addMatrix(b11, b12, temp2, newSize);
    multiplyStrassen(temp1, temp2, p6, newSize);

    // p7 = (a12-a22) * (b21+b22)
    subtractMatrix(a12, a22, temp1, newSize);
    addMatrix(b21, b22, temp2, newSize);
    multiplyStrassen(temp1, temp2, p7, newSize);

    int c11[MAX][MAX], c12[MAX][MAX], c21[MAX][MAX], c22[MAX][MAX];

    // c11 = p1+p4-p5+p7
    addMatrix(p1, p4, temp1, newSize);
    subtractMatrix(temp1, p5, temp2, newSize);
    addMatrix(temp2, p7, c11, newSize);

    // c12 = p3+p5
    addMatrix(p3, p5, c12, newSize);

    // c21 = p2+p4
    addMatrix(p2, p4, c21, newSize);

    // c22 = p1-p2+p3+p6
    subtractMatrix(p1, p2, temp1, newSize);
    addMatrix(temp1, p3, temp2, newSize);
    addMatrix(temp2, p6, c22, newSize);

    // Combine into result matrix C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }
}
