#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Guard {
    int start, end, cost;
};

int main() {
    // Đọc dữ liệu từ file
    ifstream input("GALLERY.INP");
    ofstream output("GALLERY.OUT");

    int n, m;
    input >> n >> m;

    vector<Guard> guards(m);
    for (int i = 0; i < m; ++i) {
        input >> guards[i].start >> guards[i].end >> guards[i].cost;
    }

    // Khởi tạo mảng dp
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    // Sắp xếp các vệ sĩ theo thời gian kết thúc để duyệt hiệu quả
    sort(guards.begin(), guards.end(), [](const Guard &a, const Guard &b) {
        return a.end < b.end;
    });

    // Quy hoạch động
    for (const auto &guard : guards) {
        for (int t = guard.end; t >= guard.start; --t) {
            if (dp[guard.start] != INT_MAX) {
                dp[t] = min(dp[t], dp[guard.start] + guard.cost);
            }
        }
    }

    // Kết quả
    int result = dp[n];
    if (result == INT_MAX) {
        output << -1 << endl; // Không thể bao phủ hết đoạn
    } else {
        output << result << endl;
    }

    // Đóng file
    input.close();
    output.close();

    return 0;
}
