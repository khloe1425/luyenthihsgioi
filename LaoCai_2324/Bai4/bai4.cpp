#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

int main() {
    std::ifstream infile("bai4.inp");
    std::ofstream outfile("bai4.out");

    if (!infile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    int k;
    infile >> k; // Đọc số lượng truy vấn
    infile.ignore(); // Bỏ qua ký tự newline sau khi đọc số nguyên

    for (int i = 0; i < k; ++i) {
        std::string s;
        std::getline(infile, s); // Đọc chuỗi ký tự S

        std::unordered_map<char, int> count; // Bản đồ để đếm số lần xuất hiện của từng ký tự

        // Đếm số lần xuất hiện của từng ký tự
        for (char c : s) {
            count[c]++;
        }

        int position = -1; // Biến để lưu vị trí của ký tự xuất hiện duy nhất
        // Tìm vị trí đầu tiên của ký tự xuất hiện duy nhất
        for (int j = 0; j < s.size(); ++j) {
            if (count[s[j]] == 1) { // Nếu ký tự xuất hiện duy nhất
                position = j + 1; // Lưu vị trí (thay đổi từ 0-index sang 1-index)
                break; // Thoát khỏi vòng lặp
            }
        }

        outfile << position << std::endl; // Ghi vị trí vào tệp
    }

    infile.close();
    outfile.close();

    return 0;
}
