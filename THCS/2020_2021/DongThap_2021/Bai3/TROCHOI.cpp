#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("TROCHOI.INP");
    ofstream outputFile("TROCHOI.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        inputFile >> a[i];
    }
    inputFile.close();

    int steps = 0;
    for (int i = 0; i < m; ++i) {
        if (a[i] != 0 && n % a[i] == 0) {
            steps++;
        }
    }

    steps %= 28032021;
    outputFile << steps << endl;
    outputFile.close();

    return 0;
}
