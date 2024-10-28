#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip> // Để sử dụng std::setprecision

int main() {
    // Đọc dữ liệu từ file DAY.INP
    std::ifstream inputFile("DAY.INP");
    int n;
    inputFile >> n; // Số công nhân

    std::vector<int> daysWorked(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> daysWorked[i]; // Số ngày làm việc của mỗi công nhân
    }
    inputFile.close();

    // Sắp xếp số ngày làm việc theo thứ tự giảm dần
    std::sort(daysWorked.rbegin(), daysWorked.rend());

    // Tính tổng số ngày làm việc
    int totalDays = 0;
    for (int days : daysWorked) {
        totalDays += days;
    }

    // Tính số ngày làm việc trung bình
    double averageDays = static_cast<double>(totalDays) / n;

    // Ghi kết quả vào file DAY.OUT
    std::ofstream outputFile("DAY.OUT");
    for (int i = 0; i < n; ++i) {
        outputFile << daysWorked[i] << (i < n - 1 ? " " : "");
    }
    outputFile << std::endl;
    outputFile << "Tong: " << totalDays << "; trung bình: " << std::fixed << std::setprecision(2) << averageDays;
    outputFile.close();

    return 0;
}
