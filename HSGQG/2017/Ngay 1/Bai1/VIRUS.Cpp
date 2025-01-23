#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if there exists a substring of length 'len' that can be copied with 'k' mismatches
bool isValid(const string &T, int len, int k) {
    int n = T.size();
    for (int start = 0; start + len <= n; ++start) {
        string substring = T.substr(start, len);
        for (int i = 0; i + len <= n; ++i) {
            if (i == start) continue; // Skip the same substring
            int mismatchCount = 0;
            for (int j = 0; j < len; ++j) {
                if (T[i + j] != substring[j]) {
                    ++mismatchCount;
                    if (mismatchCount > k) break;
                }
            }
            if (mismatchCount <= k) {
                return true;
            }
        }
    }
    return false;
}

// Binary search to find the maximum valid length
int maxLengthWithKMismatches(const string &T, int k) {
    int left = 1, right = T.size(), maxLen = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (isValid(T, mid, k)) {
            maxLen = mid;
            left = mid + 1; // Try for a longer length
        } else {
            right = mid - 1; // Try for a shorter length
        }
    }

    return maxLen;
}

int main() {
    ifstream inputFile("VIRUS.INP");
    ofstream outputFile("VIRUS.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int n;
    string T;
    inputFile >> n >> T;

    vector<int> kValues(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> kValues[i];
    }

    for (int k : kValues) {
        int result = maxLengthWithKMismatches(T, k);
        outputFile << result << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
