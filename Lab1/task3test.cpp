#include<iostream>
#include "task3source.cpp"
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

void testCase1() {
    int arr[] = {1, 2, 3, 2, 4, 2, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> result = findMultipleOccurences(arr, 2, size);
    vector<int> expected = {1, 3, 5};
    bool res = compareVectors(result, expected);

    if (res) {
        cout << "Test Case 1 Passed!" << endl;
    } else {
        cout << "Test Case 1 Failed!" << endl;
    }

}

void testCase2() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> result = findMultipleOccurences(arr, 6, size);
    vector<int> expected = {};
    bool res = compareVectors(result, expected);

    if (res) {
        cout << "Test Case 2 Passed!" << endl;
    } else {
        cout << "Test Case 2 Failed!" << endl;
    }
}

void testCase3() {
    int arr[] = {};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> result = findMultipleOccurences(arr, 1, size);
    vector<int> expected = {};
    bool res = compareVectors(result, expected);
    if (res) {
        cout << "Test Case 3 Passed!" << endl;
    } else {
        cout << "Test Case 3 Failed!" << endl;
    }
}