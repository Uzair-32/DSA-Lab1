#include<iostream>
#include<vector>
using namespace std;

vector<int> findMultipleOccurences(const int arr[], int key, int size) {
    vector<int> result;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            result.push_back(i);
        }
    }
    return result; 
}



bool compareVectors(const vector<int>& vec1, const vector<int>& vec2) {
    if (vec1.size() != vec2.size()) {
        return false;
    }
    for (size_t i = 0; i < vec1.size(); i++) {
        if (vec1[i] != vec2[i]) {
            return false;
        }
    }
    return true;
}
