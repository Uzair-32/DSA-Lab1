#include <iostream>
using namespace std;

// Function to find mode
int* findMode(int arr[], int size, int &modeCount) {
    if (size == 0) {
        modeCount = 0;
        return nullptr;
    }

    int frequency[100] = {0}; // assuming values are in range 0-99

    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }

    // Find maximum frequency
    int maxFreq = 0;
    for (int i = 0; i < 100; i++) {
        if (frequency[i] > maxFreq) {
            maxFreq = frequency[i];
        }
    }

    // Count how many elements have this frequency
    modeCount = 0;
    for (int i = 0; i < 100; i++) {
        if (frequency[i] == maxFreq) {
            modeCount++;
        }
    }

    // Store all modes
    int* result = new int[modeCount];
    int idx = 0;
    for (int i = 0; i < 100; i++) {
        if (frequency[i] == maxFreq) {
            result[idx++] = i;
        }
    }

    return result;
}


