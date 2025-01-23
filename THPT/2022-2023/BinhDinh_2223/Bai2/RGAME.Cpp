#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

void solveTestCase(vector<int>& arr, ofstream& fout) {
    int n = arr.size();
    if (n == 0) {
        fout << "0.0\n";
        return;
    }
    if (n == 1) {
        fout << fixed << setprecision(1) << arr[0] << "\n";
        return;
    }

    vector<double> dp(n, 0.0);
    dp[0] = arr[0];
    dp[1] = max((double)arr[1], (arr[0] + arr[1]) / 2.0);

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + (arr[i - 1] + arr[i]) / 2.0);
        dp[i] = max(dp[i], dp[i - 2] + arr[i]);
    }

    fout << fixed << setprecision(1) << dp[n - 1] << "\n";
}

int main() {
    ifstream fin("RGAME.INP");
    ofstream fout("RGAME.OUT");

    int T;
    fin >> T;

    while (T--) {
        int n;
        fin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            fin >> arr[i];
        }
        solveTestCase(arr, fout);
    }

    fin.close();
    fout.close();

    return 0;
}
