#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

void decode_message(const std::string &input_file, const std::string &output_file) {
    std::ifstream infile(input_file);
    std::ofstream outfile(output_file);

    // Đọc độ dài n (không cần thiết để giải mã)
    int n;
    infile >> n;
    infile.ignore(); // Bỏ qua ký tự newline sau khi đọc n

    // Đọc nội dung mã hóa
    std::string coded_message;
    std::getline(infile, coded_message);

    std::vector<std::string> decoded_words;
    size_t i = 0;

    while (i < coded_message.length()) {
        char number = coded_message[i];
        if (number == '1' || number == '2') {
            i++; // Di chuyển đến ký tự đầu của từ
            size_t word_start = i;

            // Tìm vị trí kết thúc của từ
            while (i < coded_message.length() && coded_message[i] != '1' && coded_message[i] != '2') {
                i++;
            }

            std::string word = coded_message.substr(word_start, i - word_start); // Lấy từ mã hóa
            if (number == '2') {
                std::reverse(word.begin(), word.end()); // Đảo ngược từ nếu đầu là '2'
            }

            decoded_words.push_back(word); // Thêm từ vào danh sách
        }
    }

    for (size_t j = 0; j < decoded_words.size(); j++) {
        outfile << decoded_words[j];
        if (j < decoded_words.size() - 1) {
            outfile << " "; 
        }
    }
    outfile << std::endl;

    infile.close();
    outfile.close();
}

int main() {
    decode_message("THU.INP", "THU.OUT");

    return 0;
}
