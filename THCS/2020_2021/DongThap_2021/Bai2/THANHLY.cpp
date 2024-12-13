#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("THANHLY.INP");
    ofstream outputFile("THANHLY.OUT");

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

    int maxRevenue = 0;

    for (int price = 1; price <= 100; ++price) {
        int revenue = 0;
        for (int i = 0; i < m; ++i) {
            if (a[i] >= price) {
                revenue += price;
            }
        }
        maxRevenue = max(maxRevenue, revenue);
    }

    outputFile << maxRevenue << endl;
    outputFile.close();

    return 0;
}
