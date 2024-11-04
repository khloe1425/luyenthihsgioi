#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream infile("TUDAI.INP");
    std::ofstream outfile("TUDAI.OUT");
    
    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    
    std::string input;
    std::getline(infile, input);  // Đọc dòng đầu tiên từ tệp
    
    // Thay thế ký tự '_' bằng dấu cách
    for (char &c : input) {
        if (c == '_') {
            c = ' ';
        }
    }
    
    std::istringstream iss(input);
    std::string word;
    int max_length = 0;
    std::string longest_word;
    
    // Lặp qua từng từ trong chuỗi
    while (iss >> word) {
        int word_length = word.length();
        // Cập nhật nếu tìm thấy từ dài hơn hoặc bằng
        if (word_length >= max_length) {
            max_length = word_length;
            longest_word = word;
        }
    }
    
    // Ghi kết quả vào tệp
    outfile << max_length << std::endl;
    outfile << longest_word << std::endl;
    
    // Đóng tệp
    infile.close();
    outfile.close();
    
    return 0;
}