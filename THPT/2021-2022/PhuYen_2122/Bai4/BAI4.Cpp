#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Hàm tìm dãy con chung dài nhất (LCS)
string find_lcs(const string& X, const string& Y) {
    int m = X.length(), n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Tính mảng dp
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Truy ngược để tìm xâu LCS
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs; // Thêm ký tự vào kết quả
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    ifstream infile("BAI4.INP");
    ofstream outfile("BAI4.OUT");

    string X, Y;
    getline(infile, X);
    getline(infile, Y);

    // Tìm xâu con chung dài nhất
    string lcs = find_lcs(X, Y);

    // Ghi kết quả ra file
    if (lcs.empty()) {
        outfile << -1 << endl; // Không tìm được xâu chung
    } else {
        outfile << lcs << endl; // Ghi xâu chung dài nhất
    }

    infile.close();
    outfile.close();

    return 0;
}
