#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Primitives
void print(int val) {
    cout << val << endl;
}

void print(bool val) {
    cout << (val ? "true" : "false") << endl;
}

void print(double val) {
    cout << val << endl;
}

void print(const string& val) {
    cout << "\"" << val << "\"" << endl;
}

// Vector<int>
void print(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Vector<string>
void print(const vector<string>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Vector<vector<int>>
void print(const vector<vector<int>>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j];
            if (j < vec[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Vector<vector<string>>
void print(const vector<vector<string>>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < vec[i].size(); j++) {
            cout << "\"" << vec[i][j] << "\"";
            if (j < vec[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Vector<bool>
void print(const vector<bool>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << (vec[i] ? "true" : "false");
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Vector<double>
void print(const vector<double>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}
