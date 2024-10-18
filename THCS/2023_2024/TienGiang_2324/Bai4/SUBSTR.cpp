#include <iostream>
#include <fstream>
#include <string>

std::string find_shortest_prefix(const std::string& s) {
    int n = s.length();
    for (int len = 1; len <= n / 2; ++len) {
        if (n % len == 0) { // Kiểm tra nếu chiều dài xâu chia hết cho len
            std::string prefix = s.substr(0, len);
            std::string repeated = "";
            // Tạo xâu từ đoạn đầu
            for (int j = 0; j < n / len; ++j) {
                repeated += prefix;
            }
            // Kiểm tra xem xâu lặp lại có giống với xâu ban đầu không
            if (repeated == s) {
                return prefix; // Trả về đoạn đầu ngắn nhất
            }
        }
    }
    return ""; // Nếu không tìm thấy, trả về chuỗi rỗng
}

int main() {
    std::ifstream infile("SUBSTR.INP");
    std::ofstream outfile("SUBSTR.OUT");

    int n;
    infile >> n;
    infile.ignore(); // Bỏ qua ký tự newline sau khi đọc n
    std::string result = "";
    
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::getline(infile, s); // Đọc từng xâu
        std::string prefix = find_shortest_prefix(s);
        if (!prefix.empty()) {
            result += prefix; // Ghép các đoạn đầu ngắn nhất
        }
    }

    // Ghi kết quả ra file
    outfile << result;

    infile.close();
    outfile.close();
    return 0;
}
