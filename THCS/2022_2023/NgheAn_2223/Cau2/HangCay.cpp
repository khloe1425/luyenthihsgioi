#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream input("HangCay.INP");
    std::ofstream output("HangCay.OUT");

    int n, m;
    input >> n >> m; // Đọc số cây và số vòi nước

    // Mảng để theo dõi các cây đã được tưới nước
    std::vector<bool> trees_watered(n + 1, false);

    // Đọc thông tin vòi nước
    for (int i = 0; i < m; ++i) {
        int x_i, r_i;
        input >> x_i >> r_i; // Đọc vị trí và bán kính vòi nước

        // Tính khoảng cách tưới nước
        int left_bound = std::max(1, x_i - r_i);
        int right_bound = std::min(n, x_i + r_i);

        // Đánh dấu các cây được tưới nước
        for (int j = left_bound; j <= right_bound; ++j) {
            trees_watered[j] = true;
        }
    }

    // Đếm số lượng cây đã được tưới nước
    int watered_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (trees_watered[i]) {
            ++watered_count;
        }
    }

    // Xuất kết quả ra tệp
    output << watered_count << std::endl;

    input.close();
    output.close();

    return 0;
}
