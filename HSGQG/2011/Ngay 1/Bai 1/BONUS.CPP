#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// Đường dẫn file
const string INPUT_FILE = "BONUS.INP";
const string OUTPUT_FILE = "BONUS.OUT";

int main() {
    // Đọc dữ liệu từ file
    ifstream input(INPUT_FILE);
    ofstream output(OUTPUT_FILE);

    int n, k;
    input >> n >> k;

    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));

    // Nhập ma trận
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            input >> a[i][j];
            // Tính prefix sum trực tiếp
            prefix[i][j] = a[i][j]
                         + prefix[i - 1][j]
                         + prefix[i][j - 1]
                         - prefix[i - 1][j - 1];
        }
    }

    input.close();

    int max_sum = 0;

    // Duyệt qua tất cả các hình vuông k x k
    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= n; ++j) {
            int x1 = i - k + 1, y1 = j - k + 1;
            int x2 = i, y2 = j;

            // Tính tổng hình vuông k x k
            int current_sum = prefix[x2][y2]
                            - prefix[x1 - 1][y2]
                            - prefix[x2][y1 - 1]
                            + prefix[x1 - 1][y1 - 1];

            max_sum = max(max_sum, current_sum);
        }
    }

    // Ghi kết quả ra file
    output << max_sum << endl;
    output.close();

    return 0;
}
