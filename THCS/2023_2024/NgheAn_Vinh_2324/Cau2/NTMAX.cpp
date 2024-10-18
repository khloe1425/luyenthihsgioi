#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(long long num) {
    if (num < 2) return false;
    for (long long i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    // Mở file NTMAX.INP để đọc dữ liệu và NTMAX.OUT để ghi kết quả
    ifstream input("NTMAX.INP");
    ofstream output("NTMAX.OUT");

    string S;
    input >> S;

    int digitCount = 0;
    long long maxPrime = 0;
    string currentNum = "";

    for (char ch : S) {
        if (isdigit(ch)) {
            // Nếu là ký tự số
            digitCount++;
            currentNum += ch;  // Thêm vào chuỗi số hiện tại
        } else {
            // Khi gặp ký tự không phải số, xử lý chuỗi số đã gom được
            if (!currentNum.empty()) {
                long long num = stoll(currentNum);
                if (isPrime(num)) {
                    maxPrime = max(maxPrime, num);  // Tìm số nguyên tố lớn nhất
                }
            }
            currentNum = "";  // Reset chuỗi số hiện tại
        }
    }
    // Kiểm tra lần cuối nếu chuỗi kết thúc bằng một số
    if (!currentNum.empty()) {
        long long num = stoll(currentNum);
        if (isPrime(num)) {
            maxPrime = max(maxPrime, num);
        }
    }

    // Ghi kết quả ra file NTMAX.OUT
    output << digitCount << endl;
    output << (maxPrime > 0 ? maxPrime : 0) << endl;

    // Đóng các file
    input.close();
    output.close();

    return 0;
}
