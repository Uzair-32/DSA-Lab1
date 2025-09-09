#include <iostream>
#include "task5source.h"
using namespace std;

void testCase1();
void testCase2();
void testCase3();

int main() {
    testCase1();
    testCase2();
    testCase3();
    return 0;
}

// n = 0  empty triangle
void testCase1() {
    int pascal[20][20] = {0};
    int n = 0;
    generatePascalsTriangle(pascal, n);
    printPascalsTriangle(pascal, n);

    if (n == 0) {
        cout << "Test Case 1 Passed!" << endl;
    } else {
        cout << "Test Case 1 Failed!" << endl;
    }
    cout << endl;
}

// n = 1  only row {1}
void testCase2() {
    int pascal[20][20] = {0};
    int n = 1;
    generatePascalsTriangle(pascal, n);
    printPascalsTriangle(pascal, n);

    int expected[] = {1};
    if (compareArrays(pascal[0], expected, 1)) {
        cout << "Test Case 2 Passed!" << endl;
    } else {
        cout << "Test Case 2 Failed!" << endl;
    }
    cout << endl;
}

// n = 5  check row 5  {1, 4, 6, 4, 1}
void testCase3() {
    int pascal[20][20] = {0};
    int n = 5;
    generatePascalsTriangle(pascal, n);
    printPascalsTriangle(pascal, n);

    int expected[] = {1, 4, 6, 4, 1};
    if (compareArrays(pascal[4], expected, 5)) {
        cout << "Test Case 3 Passed!" << endl;
    } else {
        cout << "Test Case 3 Failed!" << endl;
    }
    cout << endl;
}