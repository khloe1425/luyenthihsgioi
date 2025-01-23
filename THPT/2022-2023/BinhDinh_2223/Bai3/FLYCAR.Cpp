#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calculateMinimumFuel(const vector<int>& obstacles, int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
    dp[0][0] = 0;  // Bắt đầu từ độ cao 0 với 0 lần thay đổi độ cao.

    for (int i = 1; i <= n; i++) {
        for (int changes = 0; changes <= k; changes++) {
            for (int prev_height = 0; prev_height <= 100; prev_height++) {
                if (dp[i - 1][changes] != INT_MAX) {
                    int current_height = max(prev_height, obstacles[i - 1]);
                    int fuel_cost = abs(current_height - prev_height);
                    dp[i][changes] = min(dp[i][changes], dp[i - 1][changes] + fuel_cost);
                }
                if (changes > 0) {
                    dp[i][changes] = min(dp[i][changes], dp[i - 1][changes - 1]);
                }
            }
        }
    }

    int min_fuel = INT_MAX;
    for (int changes = 0; changes <= k; changes++) {
        min_fuel = min(min_fuel, dp[n][changes]);
    }

    return min_fuel;
}

int main() {
    ifstream infile("FLYCAR.INP");
    ofstream outfile("FLYCAR.OUT");

    int n, k;
    infile >> n >> k;

    vector<int> obstacles(n);
    for (int i = 0; i < n; i++) {
        infile >> obstacles[i];
    }

    // Tính kết quả
    int result = calculateMinimumFuel(obstacles, n, k);

    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
