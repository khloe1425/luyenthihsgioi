#include <iostream>
#include <fstream>
using namespace std;

// Hàm kiểm tra số đối xứng
bool isPalindrome(int num) {
    int original = num, reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

// Hàm đảo ngược số
int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    // Mở file input và output
    ifstream inputFile("DOIXUNG.INP");
    ofstream outputFile("DOIXUNG.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    // Đọc số từ file
    int n;
    inputFile >> n;

    int steps = 0; // Số lần biến đổi
    while (!isPalindrome(n)) {
        int reversed = reverseNumber(n); // Đảo ngược số
        n += reversed;                   // Cộng với số đảo ngược
        steps++;                         // Tăng số lần biến đổi
    }

    // Ghi kết quả ra file
    outputFile << n << endl; // Số đối xứng cuối cùng
    outputFile << steps << endl; // Số lần biến đổi

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
