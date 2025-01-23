#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Hàm mã hóa ký tự
char shiftChar(char c, int m) {
    return 'a' + (c - 'a' + m) % 26;
}

// Hàm mã hóa chuỗi
string encode(const string &s, int m) {
    string result = "";
    for (char c : s) {
        result += shiftChar(c, m);
    }
    return result;
}

int main() {
    // Đọc dữ liệu vào
    ifstream input("PASSWORD.INP");
    ofstream output("PASSWORD.OUT");

    int m; // Số bước dịch chuyển
    string T; // Chuỗi T

    input >> m >> T;

    string P = "xau"; // Mật khẩu cần tìm
    int L = P.length(); // Độ dài của mật khẩu

    bool found = false;

    // Duyệt qua tất cả các chuỗi con độ dài L trong T
    for (size_t i = 0; i + L <= T.length(); ++i) {
        string substring = T.substr(i, L);
        string encoded = encode(substring, m);
        if (encoded == P) {
            found = true;
            break;
        }
    }

    // Ghi kết quả
    if (found) {
        output << P << endl;
    } else {
        output << 0 << endl;
    }

    // Đóng file
    input.close();
    output.close();

    return 0;
}
