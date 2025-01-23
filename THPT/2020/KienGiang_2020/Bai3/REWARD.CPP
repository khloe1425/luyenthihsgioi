#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("REWARD.INP");
    ofstream output("REWARD.OUT");

    int N;
    input >> N;

    vector<int> rewards(N + 1);
    for (int i = 1; i <= N; ++i) {
        input >> rewards[i];
    }

    // Mảng dp để lưu giá trị lớn nhất tại mỗi vị trí
    vector<long long> dp(N + 1, 0);
    vector<int> trace(N + 1, -1); // Dùng để truy vết phần thưởng được chọn

    // Trường hợp đặc biệt
    if (N == 1) {
        output << rewards[1] << endl;
        output << "1" << endl;
        return 0;
    }

    // Khởi tạo giá trị ban đầu
    dp[1] = rewards[1];
    dp[2] = rewards[1] + rewards[2];

    // Quy hoạch động
    for (int i = 3; i <= N; ++i) {
        if (dp[i - 2] + rewards[i] > dp[i - 1]) {
            dp[i] = dp[i - 2] + rewards[i];
            trace[i] = i - 2;
        } else {
            dp[i] = dp[i - 1];
            trace[i] = i - 1;
        }
    }

    // Truy vết để tìm các phần thưởng được chọn
    vector<int> selected;
    int i = N;
    while (i > 0) {
        if (trace[i] == i - 2) {
            selected.push_back(i);
            i -= 2;
        } else {
            i--;
        }
    }

    // Đảo ngược danh sách để có thứ tự tăng dần
    reverse(selected.begin(), selected.end());

    // Ghi kết quả ra file
    output << dp[N] << endl; // Tổng giá trị lớn nhất
    for (int idx : selected) {
        output << idx << " ";
    }
    output << endl;

    input.close();
    output.close();

    return 0;
}
