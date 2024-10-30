#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ifstream input("STRING.INP");
    ofstream output("STRING.OUT");

    string s;
    getline(input, s); // Đọc xâu từ tệp

    string letters; // Chứa các ký tự chữ
    string digits; // Chứa các ký tự số

    // Phân tách ký tự thành chữ cái và số
    for (char ch : s) {
        if (isalpha(ch)) {
            letters += ch; // Thêm chữ cái vào letters
        } else if (isdigit(ch)) {
            digits += ch; // Thêm chữ số vào digits
        }
    }

    // Đảo ngược chuỗi letters
    reverse(letters.begin(), letters.end());

    // Sắp xếp chuỗi digits
    sort(digits.begin(), digits.end());

    // Ghi kết quả vào tệp
    output << letters << endl;
    output << digits << endl;

    input.close();
    output.close();
    return 0;
}
