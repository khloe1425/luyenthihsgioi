#include <iostream>
#include <fstream>
#include <cstdlib> // Để sử dụng abs
#include <algorithm> // Để sử dụng __gcd trong C++

using namespace std;

int main() {
    ifstream inputFile("FRAC.INP");
    ofstream outputFile("FRAC.OUT");
    
    int a, b;
    inputFile >> a >> b;
    
    // Kiểm tra tính hợp lệ của phân số
    if (b == 0) {
        outputFile << "INVALID";
        return 0;
    }

    // Tìm ước chung lớn nhất giữa a và b
    int gcd = __gcd(abs(a), abs(b));

    // Rút gọn phân số
    a /= gcd;
    b /= gcd;

    // Đưa dấu âm lên tử số nếu mẫu số âm
    if (b < 0) {
        a = -a;
        b = -b;
    }

    // Xuất kết quả
    if (b == 1) {
        // Nếu mẫu số là 1, in ra tử số
        outputFile << a;
    } else if (a % b == 0) {
        // Nếu phân số là số nguyên
        outputFile << a / b;
    } else {
        // Trường hợp khác, in ra phân số tối giản
        outputFile << a << " " << b;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}