#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    std::ifstream infile("CUASO.INP");
    std::ofstream outfile("CUASO.OUT");

    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int n;
    infile >> n;  // Đọc số lượng que
    std::unordered_map<int, int> length_count;  // Đếm số lượng que theo chiều dài

    // Đọc chiều dài các que
    for (int i = 0; i < n; ++i) {
        int length;
        infile >> length;
        length_count[length]++;
    }

    int max_perimeter = 0;
    std::vector<int> sides;

    // Tìm chiều dài có đủ số lượng để tạo thành cửa sổ
    for (const auto &pair : length_count) {
        int length = pair.first;
        int count = pair.second;

        if (count >= 4) {
            // Có đủ 4 que để tạo hình vuông
            max_perimeter = std::max(max_perimeter, 4 * length);
        }
        if (count >= 2) {
            // Có đủ 2 que để tạo cạnh
            sides.push_back(length);
        }
    }

    // Nếu có ít nhất 2 chiều dài, tính chu vi của hình chữ nhật lớn nhất
    if (sides.size() >= 2) {
        std::sort(sides.rbegin(), sides.rend()); // Sắp xếp giảm dần
        max_perimeter = std::max(max_perimeter, 2 * (sides[0] + sides[1]));
    }

    // Ghi kết quả vào tệp
    if (max_perimeter > 0) {
        outfile << max_perimeter << std::endl;  // Nếu có thể ghép cửa sổ
    } else {
        outfile << -1 << std::endl;  // Không thể ghép cửa sổ nào
    }

    // Đóng tệp
    infile.close();
    outfile.close();

    return 0;
}