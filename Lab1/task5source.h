#include <iostream>
using namespace std;

void generatePascalsTriangle(int pascal[20][20], int n);
void printPascalsTriangle(int pascal[20][20], int n);

bool compareArrays(const int arr1[], const int arr2[], int size);



// Function to generate Pascal's Triangle up to n rows
void generatePascalsTriangle(int pascal[20][20], int n) {
    if (n <= 0) return;

    pascal[0][0] = 1; // first row

    for (int i = 1; i < n; i++) {
        pascal[i][0] = 1;       // first element
        pascal[i][i] = 1;       // last element
        for (int j = 1; j < i; j++) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }
}

// Print Pascal’s Triangle
void printPascalsTriangle(int pascal[20][20], int n) {
    cout << "Pascal's Triangle (n = " << n << "):" << endl;
    for (int i = 0; i < n; i++) {
        for (int space = 0; space < n - i - 1; space++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



// Compare two arrays of given size
bool compareArrays(const int arr1[], const int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

