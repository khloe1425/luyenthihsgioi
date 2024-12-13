#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("CAU4.INP");
    ofstream outputFile("CAU4.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int n, s;
    inputFile >> n >> s;
    vector<int> a(n);
    unordered_map<int, int> valueMap;

    for (int i = 0; i < n; ++i) {
        inputFile >> a[i];
    }
    inputFile.close();

    int count = 0;
    for (int i = 0; i < n; ++i) {
        int complement = s - a[i];
        if (valueMap.find(complement) != valueMap.end()) {
            count += valueMap[complement];
        }
        valueMap[a[i]]++;
    }

    outputFile << count << endl;
    outputFile.close();

    return 0;
}
