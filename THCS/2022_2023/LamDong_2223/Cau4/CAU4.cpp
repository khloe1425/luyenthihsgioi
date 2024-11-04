#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

// Hàm tìm chi phí thuê nghệ sĩ nhỏ nhất
int minCostArtists(int n, int m, const vector<tuple<int, int, int>>& performances) {
    vector<long long> dp(n + 1, numeric_limits<long long>::max());
    dp[0] = 0; // Không thuê nghệ sĩ nào tại thời điểm 0 có chi phí 0

    // Duyệt qua từng nghệ sĩ
    for (const auto& performance : performances) {
        int s, t, c;
        tie(s, t, c) = performance;

        // Cập nhật chi phí cho từng khoảng thời gian
        for (int j = n; j >= s; --j) {
            if (j >= t) {
                dp[j] = min(dp[j], dp[j - (t - s)] + c);
            }
        }
    }

    return dp[n];
}

int main() {
    ifstream inputFile("CAU4.INP");
    ofstream outputFile("CAU4.OUT");

    int n, m;
    inputFile >> n >> m;
    vector<tuple<int, int, int>> performances(m);

    for (int i = 0; i < m; ++i) {
        int s, t, c;
        inputFile >> s >> t >> c;
        performances[i] = make_tuple(s, t, c);
    }

    int result = minCostArtists(n, m, performances);
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
