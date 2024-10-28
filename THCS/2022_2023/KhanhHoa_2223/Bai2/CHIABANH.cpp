#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    // Đọc dữ liệu từ tệp CHIABANH.INP
    std::ifstream inputFile("CHIABANH.INP");
    std::vector<int> mushrooms(8);
    
    for (int i = 0; i < 8; ++i) {
        inputFile >> mushrooms[i];
    }
    inputFile.close();

    // Tính tổng lớn nhất của 4 phần tử liên tiếp
    int max_sum = 0;
    int n = mushrooms.size();

    // Duyệt qua các vị trí và lấy tổng 4 phần tử liên tiếp (tính tròn)
    for (int i = 0; i < n; ++i) {
        int current_sum = mushrooms[i] + mushrooms[(i + 1) % n] + mushrooms[(i + 2) % n] + mushrooms[(i + 3) % n];
        max_sum = std::max(max_sum, current_sum);
    }

    // Ghi kết quả ra tệp CHIABANH.OUT
    std::ofstream outputFile("CHIABANH.OUT");
    outputFile << max_sum;
    outputFile.close();

    return 0;
}
