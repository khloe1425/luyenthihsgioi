#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Hàm tìm số nhỏ nhất có n chữ số và tổng các chữ số bằng s
string findMinNumber(int n, int s) {
    if (s == 0) {
        return n == 1 ? "0" : "-1"; // Không thể có số n chữ số với tổng s = 0 trừ khi n = 1
    }

    if (s > 9 * n) {
        return "-1"; // Không thể đạt được tổng s với n chữ số
    }

    string result(n, '0'); // Khởi tạo chuỗi n chữ số đều là '0'
    s--; // Trừ 1 để đảm bảo số đầu tiên không bằng 0

    for (int i = n - 1; i >= 0; --i) {
        if (s > 9) {
            result[i] = '9'; // Gán 9 cho chữ số lớn nhất còn lại
            s -= 9;
        } else {
            result[i] = '0' + s; // Gán giá trị còn lại cho chữ số
            s = 0;
        }
    }

    result[0] = result[0] + 1; // Cộng 1 lại cho chữ số đầu tiên

    return result;
}

int main() {
    ifstream inputFile("MINNUM.INP");
    ofstream outputFile("MINNUM.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n, s;
    inputFile >> n >> s;

    string result = findMinNumber(n, s);
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
