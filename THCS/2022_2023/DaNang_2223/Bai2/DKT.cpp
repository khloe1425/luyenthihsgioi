#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>

int main() {
    // Đọc xâu ký tự từ file DKT.INP
    std::ifstream inputFile("DKT.INP");
    std::string s;
    if (inputFile.is_open()) {
        std::getline(inputFile, s);  // Đọc xâu ký tự từ file
        inputFile.close();  // Đóng file sau khi đọc
    } else {
        std::cerr << "Không thể mở file DKT.INP" << std::endl;
        return 1;  // Trả về mã lỗi nếu không mở được file
    }

    // Tạo một unordered_map để đếm số lần xuất hiện của mỗi ký tự
    std::unordered_map<char, int> char_count;

    // Đếm số lần xuất hiện của từng ký tự
    for (char c : s) {
        char_count[c]++;
    }

    // Đếm số ký tự xuất hiện ít nhất 2 lần
    int count = 0;
    for (const auto& pair : char_count) {
        if (pair.second >= 2) {
            count++;
        }
    }

    // Ghi kết quả ra file DKT.OUT
    std::ofstream outputFile("DKT.OUT");
    if (outputFile.is_open()) {
        outputFile << count;  // Ghi số lượng ký tự xuất hiện ít nhất 2 lần vào file
        outputFile.close();  // Đóng file sau khi ghi
    } else {
        std::cerr << "Không thể mở file DKT.OUT" << std::endl;
        return 1;  // Trả về mã lỗi nếu không mở được file
    }

    return 0;
}
