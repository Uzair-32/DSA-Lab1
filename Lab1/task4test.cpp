#include <iostream>
#include "task4source.cpp"
using namespace std;

void testCase1();
void testCase2();
void testCase3();
void testCase4();

int main() {
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    return 0;
}

// Pattern at the beginning
void testCase1() {
    string text = "hello world";
    string pattern = "hello";
    int result = findPatternNaive(text, pattern);
    int expected = 0;

    if (result == expected) {
        cout << "Test Case 1 Passed!" << endl;
    } else {
        cout << "Test Case 1 Failed!" << endl;
    }
}

// Pattern at the end
void testCase2() {
    string text = "this is a test";
    string pattern = "test";
    int result = findPatternNaive(text, pattern);
    int expected = 10;

    if (result == expected) {
        cout << "Test Case 2 Passed!" << endl;
    } else {
        cout << "Test Case 2 Failed!" << endl;
    }
}

// Pattern not present
void testCase3() {
    string text = "abcdefg";
    string pattern = "xyz";
    int result = findPatternNaive(text, pattern);
    int expected = -1;

    if (result == expected) {
        cout << "Test Case 3 Passed!" << endl;
    } else {
        cout << "Test Case 3 Failed!" << endl;
    }
}

// Empty pattern
void testCase4() {
    string text = "abcdef";
    string pattern = "";
    int result = findPatternNaive(text, pattern);
    int expected = -1;

    if (result == expected) {
        cout << "Test Case 4 Passed!" << endl;
    } else {
        cout << "Test Case 4 Failed!" << endl;
    }
}
