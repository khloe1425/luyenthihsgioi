#include <iostream>
#include <fstream>

int main() {
    // Đọc giá trị x từ file UTS.INP
    std::ifstream inputFile("UTS.INP");
    int x;
    inputFile >> x;  // Đọc giá trị x từ file
    inputFile.close();  // Đóng file sau khi đọc

    // Tìm ước thực sự lớn nhất của x
    int result = 1;  // Khởi tạo kết quả với 1 (ước nhỏ nhất)
    for (int i = x / 2; i >= 1; --i) {
        if (x % i == 0) {
            result = i;  // Cập nhật kết quả
            break;  // Thoát vòng lặp khi tìm thấy ước thực sự lớn nhất
        }
    }

    // Ghi kết quả ra file UTS.OUT
    std::ofstream outputFile("UTS.OUT");
    outputFile << result;  // Ghi giá trị kết quả vào file
    outputFile.close();  // Đóng file sau khi ghi

    return 0;
}
