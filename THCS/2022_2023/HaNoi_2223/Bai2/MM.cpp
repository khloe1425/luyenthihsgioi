#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <cctype>

int main() {
    std::ifstream input("MM.INP"); // Mở tệp đầu vào
    std::ofstream output("MM.OUT"); // Mở tệp đầu ra

    if (!input) {
        std::cerr << "Không thể mở tệp MM.INP" << std::endl;
        return 1;
    }

    std::string s;
    std::getline(input, s); // Đọc xâu mật thư

    std::set<int> unique_numbers; // Tập hợp để lưu trữ các số nguyên phân biệt
    std::string temp_number; // Biến tạm để lưu số

    for (char c : s) {
        if (std::isdigit(c)) {
            temp_number += c; // Thêm ký tự vào số tạm thời
        } else {
            if (!temp_number.empty()) {
                unique_numbers.insert(std::stoi(temp_number)); // Chuyển đổi thành số nguyên và thêm vào tập
                temp_number.clear(); // Reset biến tạm
            }
        }
    }

    // Kiểm tra số tạm còn lại sau vòng lặp
    if (!temp_number.empty()) {
        unique_numbers.insert(std::stoi(temp_number));
    }

    // Số lượng số nguyên phân biệt
    int result = unique_numbers.size();

    output << result << std::endl; // Ghi kết quả ra tệp MM.OUT

    // Đóng tệp
    input.close();
    output.close();

    return 0;
}
