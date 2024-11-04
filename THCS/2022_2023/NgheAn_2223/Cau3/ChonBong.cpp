#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    std::ifstream input("ChonBong.INP");
    std::ofstream output("ChonBong.OUT");

    int n, k;
    input >> n >> k; // Đọc số quả bóng và số màu

    std::vector<int> colors(n);
    std::unordered_map<int, int> color_count; // Đếm số lượng quả bóng theo màu

    // Đọc mã màu và đếm số lượng
    for (int i = 0; i < n; ++i) {
        input >> colors[i];
        color_count[colors[i]]++;
    }

    // Lưu trữ số lượng bóng theo màu vào một vector
    std::vector<int> counts;
    for (const auto& entry : color_count) {
        counts.push_back(entry.second);
    }

    // Nếu chỉ có một màu, không thể lấy được điểm
    if (counts.size() == 1) {
        output << 0 << std::endl;
        return 0;
    }

    // Tính điểm tối đa
    int max_points = 0;
    std::sort(counts.rbegin(), counts.rend()); // Sắp xếp theo số lượng bóng giảm dần

    // Số lần lấy được bóng tối đa
    while (counts.size() > 1) {
        // Lấy số lượng bóng của màu có số lượng tối đa và màu có số lượng tối thiểu
        int min_count = counts.back();
        int max_count = counts.front();

        // Điểm tăng thêm là 2 (mỗi lần lấy ra 2 bóng)
        max_points += 2;

        // Giảm số lượng bóng đã lấy ra
        counts.front()--; // Giảm màu có số lượng tối đa
        counts.back()--;  // Giảm màu có số lượng tối thiểu

        // Loại bỏ màu đã hết bóng
        if (counts.front() == 0) {
            counts.erase(counts.begin());
        }
        if (counts.back() == 0) {
            counts.pop_back();
        }

        // Sắp xếp lại số lượng
        std::sort(counts.rbegin(), counts.rend());
    }

    output << max_points << std::endl;

    input.close();
    output.close();

    return 0;
}
