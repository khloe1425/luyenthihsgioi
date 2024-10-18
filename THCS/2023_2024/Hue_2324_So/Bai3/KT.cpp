#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Hàm tìm chênh lệch tối thiểu
pair<int, pair<int, int>> find_min_difference(const vector<int>& hop_khau_trang) {
    int total_sum = 0;
    for (int mask : hop_khau_trang) {
        total_sum += mask;
    }
    
    int n = hop_khau_trang.size();
    // Tạo mảng dp
    vector<vector<bool>> dp(n + 1, vector<bool>(total_sum / 2 + 1, false));
    
    // Khởi tạo giá trị đầu tiên
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Điền mảng dp
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= total_sum / 2; ++j) {
            if (hop_khau_trang[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - hop_khau_trang[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Tìm tổng gần nhất
    int sum1;
    for (int j = total_sum / 2; j >= 0; --j) {
        if (dp[n][j]) {
            sum1 = j;
            break;
        }
    }

    int sum2 = total_sum - sum1;
    int difference = abs(sum1 - sum2);
    
    return {difference, {sum1, sum2}};
}

int main() {
    ifstream input("KT.INP");
    ofstream output("KT.OUT");

    int num_boxes;
    input >> num_boxes; 
    vector<int> masks_in_boxes(num_boxes);

    for (int i = 0; i < num_boxes; ++i) {
        input >> masks_in_boxes[i];
    }

    auto result = find_min_difference(masks_in_boxes);
    int difference = result.first;
    int sum1 = result.second.first;
    int sum2 = result.second.second;

    vector<int> school1;
    vector<int> school2;
    int remaining_masks = sum1;

    for (int mask : masks_in_boxes) {
        if (remaining_masks - mask >= 0) {
            school1.push_back(mask);
            remaining_masks -= mask;
        } else {
            school2.push_back(mask);
        }
    }

    output << difference << "\n";
    for (size_t i = 0; i < school1.size(); ++i) {
        output << school1[i];
        if (i < school1.size() - 1) output << " ";
    }
    output << "\n";
    for (size_t i = 0; i < school2.size(); ++i) {
        output << school2[i];
        if (i < school2.size() - 1) output << " "; 
    }
    output << "\n";
    output << sum1 << " " << sum2 << "\n";

    input.close();
    output.close();

    return 0;
}
