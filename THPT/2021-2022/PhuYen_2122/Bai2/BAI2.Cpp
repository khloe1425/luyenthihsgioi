#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Hàm xóa khoảng trắng dư thừa
string trim_and_reduce_spaces(const string &str) {
    string result;
    bool in_space = false;
    for (char c : str) {
        if (isspace(c)) {
            if (!in_space) {
                result += ' ';
                in_space = true;
            }
        } else {
            result += c;
            in_space = false;
        }
    }
    // Xóa khoảng trắng ở đầu và cuối
    result.erase(0, result.find_first_not_of(' '));
    result.erase(result.find_last_not_of(' ') + 1);
    return result;
}

// Hàm chuyển xâu thành chữ thường
string to_lowercase(const string &str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Hàm chuyển xâu thành chữ in hoa
string to_uppercase(const string &str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Hàm chuẩn hóa mỗi từ (viết hoa ký tự đầu)
string capitalize_words(const string &str) {
    stringstream ss(str);
    string word, result;
    while (ss >> word) {
        word[0] = toupper(word[0]);
        for (size_t i = 1; i < word.length(); i++) {
            word[i] = tolower(word[i]);
        }
        if (!result.empty()) result += ' ';
        result += word;
    }
    return result;
}

int main() {
    ifstream infile("BAI2.INP");
    ofstream outfile("BAI2.OUT");

    string line;
    while (getline(infile, line)) {
        // Bước 1: Xóa khoảng trắng dư thừa
        string trimmed_line = trim_and_reduce_spaces(line);

        // Bước 2: Chuyển toàn bộ thành chữ thường
        string lower_case_line = to_lowercase(trimmed_line);

        // Bước 3: Viết hoa ký tự đầu của mỗi từ
        string capitalized_line = capitalize_words(trimmed_line);

        // Bước 4: Chuyển toàn bộ thành chữ in hoa
        string upper_case_line = to_uppercase(trimmed_line);

        // Ghi kết quả ra file
        outfile << trimmed_line << endl;
        outfile << lower_case_line << endl;
        outfile << capitalized_line << endl;
        outfile << upper_case_line << endl;
        outfile << "=" << endl; // Dòng phân cách
    }

    infile.close();
    outfile.close();

    return 0;
}
