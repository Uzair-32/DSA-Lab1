#include <iostream>
#include "task6source.h"
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

// Unique mode test
void testCase1() {
    int arr[] = {1, 2, 2, 3, 4};
    int size = 5;
    int modeCount = 0;

    int* modes = findMode(arr, size, modeCount);

    cout << "Test Case 1 (Unique Mode): ";
    if (modeCount == 1 && modes[0] == 2) {
        cout << "Passed!" << endl;
    } else {
        cout << "Failed!" << endl;
    }

    delete[] modes;
}

// Multiple modes test
void testCase2() {
    int arr[] = {1, 2, 2, 3, 3};
    int size = 5;
    int modeCount = 0;

    int* modes = findMode(arr, size, modeCount);

    cout << "Test Case 2 (Multiple Modes): ";
    if (modeCount == 2 && ((modes[0] == 2 && modes[1] == 3) || (modes[0] == 3 && modes[1] == 2))) {
        cout << "Passed!" << endl;
    } else {
        cout << "Failed!" << endl;
    }

    delete[] modes;
}

// Empty array test
void testCase3() {
    int arr[] = {};
    int size = 0;
    int modeCount = 0;

    int* modes = findMode(arr, size, modeCount);

    cout << "Test Case 3 (Empty Array): ";
    if (modes == nullptr && modeCount == 0) {
        cout << "Passed!" << endl;
    } else {
        cout << "Failed!" << endl;
    }
}