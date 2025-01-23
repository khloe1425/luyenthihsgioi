#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("LNACS.INP");
    ofstream output("LNACS.OUT");

    // Read the sizes of the arrays
    int m, n;
    input >> m >> n;

    vector<int> A(m), B(n);

    // Read array A
    for (int i = 0; i < m; i++) {
        input >> A[i];
    }

    // Read array B
    for (int i = 0; i < n; i++) {
        input >> B[i];
    }

    // Dynamic programming table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                // Include this element if non-adjacent condition is satisfied
                dp[i][j] = max(dp[i][j], dp[i - 2][j - 2] + 1);
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Write the result to output
    output << dp[m][n] << endl;

    input.close();
    output.close();

    return 0;
}
