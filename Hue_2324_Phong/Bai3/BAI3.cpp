#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream infile("MUAHANG.INP");
    ofstream outfile("MUAHANG.OUT");

    int N, M;
    infile >> N >> M;

    vector<int> weights(N + 1);
    vector<int> values(N + 1);
    
    for (int i = 1; i <= N; ++i) {
        infile >> weights[i] >> values[i];
    }
    
    // Khởi tạo bảng dp
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    // Điền giá trị cho bảng dp
    for (int i = 1; i <= N; ++i) {
        for (int w = 1; w <= M; ++w) {
            if (weights[i] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i]] + values[i]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    // Tìm giá trị lớn nhất có thể đạt được
    int max_value = dp[N][M];
    
    // Truy ngược lại các hàng hóa đã chọn
    vector<int> chosen_items;
    int w = M;
    for (int i = N; i >= 1; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            chosen_items.push_back(i);
            w -= weights[i];
        }
    }

    // Sắp xếp chỉ số các hàng hóa theo thứ tự từ nhỏ đến lớn
    sort(chosen_items.begin(), chosen_items.end());
    
    // Tính tổng trọng lượng của các hàng hóa đã chọn
    int total_weight = 0;
    for (int item : chosen_items) {
        total_weight += weights[item];
    }

    // Ghi kết quả ra file MUAHANG.OUT
    outfile << max_value << endl;
    for (size_t i = 0; i < chosen_items.size(); ++i) {
        if (i > 0) outfile << " ";
        outfile << chosen_items[i];
    }
    outfile << endl;
    outfile << total_weight << endl;

    return 0;
}
