#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Hàm tính tổng giá trị lớn nhất của các cổ vật mà Aladdin có thể lấy
int max_sum_of_objects(int n, int k, const std::vector<int>& values) {
    // Mảng DP để lưu tổng giá trị lớn nhất có thể thu được khi chọn cổ vật kết thúc tại mỗi vị trí i
    std::vector<int> dp(n, 0);

    int max_sum = 0;

    // Duyệt qua từng cổ vật i
    for (int i = 0; i < n; i++) {
        // Chỉ xử lý nếu giá trị của cổ vật tại i nhỏ hơn hoặc bằng k
        if (values[i] <= k) {
            // Giá trị ban đầu của dp[i] là giá trị của cổ vật i vì Aladdin có thể chỉ chọn cổ vật đó
            dp[i] = values[i];
            
            // Duyệt các cổ vật trước đó để kiểm tra điều kiện
            for (int j = 0; j < i; j++) {
                // Kiểm tra nếu giá trị của cổ vật j nhỏ hơn giá trị của cổ vật i và cổ vật j cũng thoả mãn điều kiện <= k
                if (values[j] < values[i] && values[j] <= k) {
                    // Cập nhật dp[i] với tổng giá trị lớn nhất khi chọn cổ vật kết thúc tại i
                    dp[i] = std::max(dp[i], dp[j] + values[i]);
                }
            }
            
            // Cập nhật tổng giá trị lớn nhất
            max_sum = std::max(max_sum, dp[i]);
        }
    }

    return max_sum;
}


int main() {
    std::ifstream infile("RALADDIN.INP");
    std::ofstream outfile("RALADDIN.OUT");

    // Kiểm tra xem file đầu vào và đầu ra có mở thành công không
    if (!infile || !outfile) {
        std::cerr << "Lỗi mở file đầu vào hoặc đầu ra!" << std::endl;
        return 1;
    }

    int n, k;
    infile >> n >> k; // Đọc số lượng cổ vật và giá trị tối đa k

    std::vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        infile >> values[i]; // Đọc giá trị của từng cổ vật
    }

    // Tính tổng giá trị lớn nhất và ghi vào file đầu ra
    int result = max_sum_of_objects(n, k, values);
    outfile << result << std::endl;

    infile.close();
    outfile.close();

    return 0;
}

