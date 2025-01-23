#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Mở file input và output
    ifstream inputFile("ROBOT.INP");
    ofstream outputFile("ROBOT.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    unsigned long long N; // Số lần nhảy
    inputFile >> N;

    // Tính vị trí cuối cùng của robot
    unsigned long long position = 0; // Vị trí bắt đầu từ ô 'A' (ô thứ 1)
    for (unsigned long long i = 1; i <= N; ++i) {
        position += (2 * i - 1); // Công thức nhảy: lần thứ i nhảy (2*i - 1) ô
    }

    // Vì bảng chữ cái lặp lại từ 'A' đến 'Z' (26 ký tự)
    char result = 'A' + (position % 26);

    // Ghi ký tự ra file output
    outputFile << result;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
