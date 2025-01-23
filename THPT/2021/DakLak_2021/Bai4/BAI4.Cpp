#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream inputFile("BAI4.INP");
    ofstream outputFile("BAI4.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    vector<int> a(N + 1); // Mảng lưu giá trị của các cây
    for (int i = 1; i <= N; ++i) {
        inputFile >> a[i];
    }

    // Mảng DP lưu giá trị lớn nhất có thể đạt được từ cây i đến cuối
    vector<long long> dp(N + 4, 0); // Dư 3 phần tử để tránh tràn biên

    // Quy hoạch động từ cuối về đầu
    for (int i = N; i >= 1; --i) {
        // Chọn 1 cây
        dp[i] = a[i] + dp[i + 1];
        // Chọn 2 cây
        if (i + 1 <= N) {
            dp[i] = max(dp[i], a[i] + a[i + 1] + dp[i + 2]);
        }
        // Chọn 3 cây
        if (i + 2 <= N) {
            dp[i] = max(dp[i], a[i] + a[i + 1] + a[i + 2] + dp[i + 3]);
        }
    }

    // Ghi kết quả
    outputFile << dp[1] << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
