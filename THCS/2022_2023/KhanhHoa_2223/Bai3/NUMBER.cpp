#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char findKthDigit(long long K) {
    long long digitLength = 1; // Độ dài chữ số (1 cho 1-9, 2 cho 10-99, ...)
    long long countOfNumbers = 9; // Số lượng số có độ dài `digitLength`
    long long startNumber = 1; // Số bắt đầu cho mỗi độ dài

    // Tìm khoảng độ dài chữ số cho K
    while (K > digitLength * countOfNumbers) {
        K -= digitLength * countOfNumbers;
        digitLength++;
        countOfNumbers *= 10;
        startNumber *= 10;
    }

    // Xác định số mà chữ số thứ K nằm trong đó
    long long numberIndex = (K - 1) / digitLength; // Tính chỉ số số
    long long digitIndex = (K - 1) % digitLength; // Tính chỉ số chữ số trong số

    long long actualNumber = startNumber + numberIndex; // Số thực tế
    string numberStr = to_string(actualNumber); // Chuyển đổi số thành chuỗi để lấy chữ số cụ thể
    
    return numberStr[digitIndex]; // Trả về chữ số cụ thể
}

int main() {
    // Đọc dữ liệu từ tệp NUMBER.INP
    ifstream inputFile("NUMBER.INP");
    long long K;
    inputFile >> K;

    // Tìm chữ số thứ K
    char resultDigit = findKthDigit(K);

    // Ghi kết quả ra tệp NUMBER.OUT
    ofstream outputFile("NUMBER.OUT");
    outputFile << resultDigit << endl;

    return 0;
}
