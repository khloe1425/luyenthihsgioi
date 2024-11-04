#include <iostream>
#include <fstream>
#include <string>

void count_candies(const std::string& input_file, const std::string& output_file) {
    std::ifstream infile(input_file);
    std::string results;

    // Đọc nội dung tệp
    if (infile.is_open()) {
        std::getline(infile, results);
        infile.close();
    } else {
        std::cerr << "Không thể mở tệp " << input_file << std::endl;
        return;
    }

    // Khởi tạo số kẹo cho Đức và Nhi
    int candies_Duc = 0;
    int candies_Nhi = 0;

    // Đếm số kết quả
    for (char result : results) {
        if (result == 'D') {
            candies_Duc++;
        } else if (result == 'N') {
            candies_Nhi++;
        }
        // 'H' không cần xử lý vì không ai thắng
    }

    // Ghi kết quả vào tệp
    std::ofstream outfile(output_file);
    if (outfile.is_open()) {
        outfile << candies_Duc << " " << candies_Nhi << "\n";
        outfile.close();
    } else {
        std::cerr << "Không thể ghi vào tệp " << output_file << std::endl;
    }
}

int main() {
    std::string input_path = "./GAME.INP";
    std::string output_path = "./GAME.OUT";
    
    count_candies(input_path, output_path);
    
    return 0;
}
