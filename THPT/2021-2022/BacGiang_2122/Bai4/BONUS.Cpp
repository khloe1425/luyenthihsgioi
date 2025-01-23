#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("BONUS.INP");
    ofstream fout("BONUS.OUT");

    int n;
    fin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }

    long long totalWeight = 0;

    for (int i = 0; i < n; i++) {
        int maxVal = a[i];
        int minVal = a[i];
        for (int j = i; j < n; j++) {
            maxVal = max(maxVal, a[j]);
            minVal = min(minVal, a[j]);
            totalWeight += (maxVal - minVal);
        }
    }

    fout << totalWeight << endl;

    fin.close();
    fout.close();
    return 0;
}
