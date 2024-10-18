#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

bool isNumeric(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

int main() {
    std::ifstream infile("Sortx.INP");
    std::ofstream outfile("Sortx.OUT");

    int n;
    infile >> n;
    infile.ignore(); // Bỏ qua dòng mới sau khi đọc n

    std::vector<std::string> strings(n);
    std::string line;
    std::getline(infile, line);
    std::istringstream iss(line);

    // Đọc vào tất cả các chuỗi
    for (int i = 0; i < n; ++i) {
        iss >> strings[i];
    }

    // Tách các chuỗi số và không phải số
    std::vector<std::string> numeric_strings;
    std::vector<std::string> non_numeric_strings;

    for (const auto& str : strings) {
        if (isNumeric(str)) {
            numeric_strings.push_back(str);
        } else {
            non_numeric_strings.push_back(str);
        }
    }

    // Sắp xếp các chuỗi số
    std::sort(numeric_strings.begin(), numeric_strings.end(), [](const std::string& a, const std::string& b) {
        return std::stoi(a) < std::stoi(b);
    });

    // Kết hợp lại danh sách theo thứ tự ban đầu
    std::vector<std::string> result;
    auto num_it = numeric_strings.begin();
    for (const auto& str : strings) {
        if (isNumeric(str)) {
            result.push_back(*num_it);
            ++num_it;
        } else {
            result.push_back(str);
        }
    }

    // Ghi kết quả ra file
    for (const auto& str : result) {
        outfile << str << " ";
    }
    outfile << std::endl;

    infile.close();
    outfile.close();

    return 0;
}
