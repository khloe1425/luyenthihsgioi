#include <iostream>
#include <fstream>
using namespace std;

// Hàm tính lũy thừa nhanh modulo
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    // Mở file input và output
    ifstream inputFile("MATHS.INP");
    ofstream outputFile("MATHS.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    // Đọc giá trị a và b
    long long a, b;
    inputFile >> a >> b;

    // Đảm bảo a luôn nhỏ hơn hoặc bằng b
    if (a > b) swap(a, b);

    // Tìm các vị trí ô chia hết cho 127 trong đoạn [a, b]
    long long first = (a % 127 == 0) ? a : (a + (127 - a % 127));
    long long last = (b % 127 == 0) ? b : (b - b % 127);

    // Nếu không có ô nào chia hết cho 127
    if (first > b || last < a) {
        outputFile << 0 << endl;
        return 0;
    }

    // Tính tổng số hạt thóc
    long long sum = 0;
    for (long long n = first; n <= last; n += 127) {
        // Số hạt thóc trên ô thứ n là 2^{(n-1) % 127} % 127
        long long powerValue = powerMod(2, (n - 1) % 127, 127);
        sum += powerValue; // Cộng vào tổng
    }

    // Ghi kết quả ra file
    outputFile << sum << endl;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
