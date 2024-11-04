#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Hàm chuyển đổi từ số thập phân sang số La Mã
string decimalToRoman(int num) {
    // Bảng các số La Mã và giá trị tương ứng
    vector<pair<int, string>> roman_numerals = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string result = "";

    // Lặp qua từng giá trị La Mã từ lớn tới bé
    for (size_t i = 0; i < roman_numerals.size(); i++) {
        while (num >= roman_numerals[i].first) {
            result += roman_numerals[i].second;
            num -= roman_numerals[i].first;
        }
    }

    return result;
}

int main() {
    // Mở file BAI1.INP để đọc dữ liệu
    ifstream inp_file("BAI1.INP");
    ofstream out_file("BAI1.OUT");

    if (!inp_file || !out_file) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int num;
    // Đọc từng số từ file và chuyển đổi
    while (inp_file >> num) {
        string roman = decimalToRoman(num);
        out_file << roman << endl;
    }

    // Đóng file
    inp_file.close();
    out_file.close();

    return 0;
}
