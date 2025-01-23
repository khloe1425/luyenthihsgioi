#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ifstream input("DIGIT.INP");
    ofstream output("DIGIT.OUT");

    // Đọc dữ liệu đầu vào
    string M;
    int L, X;
    input >> M >> L >> X;

    // Thực hiện L lần biến đổi
    for (int i = 0; i < L; ++i) {
        string newM = "";  // Chuỗi mới
        unordered_map<char, int> countMap;  // Đếm số lần xuất hiện của từng ký tự
        for (char c : M) {
            countMap[c]++;
        }
        for (char c : M) {
            newM += c;                // Ký tự hiện tại
            newM += to_string(countMap[c]);  // Số lần xuất hiện
        }
        M = newM;  // Cập nhật M
    }

    // Đếm số lần ký tự X xuất hiện trong M
    int countX = 0;
    for (char c : M) {
        if (c == (X + '0')) {
            countX++;
        }
    }

    // Ghi kết quả ra file
    output << countX << endl;

    input.close();
    output.close();

    return 0;
}
