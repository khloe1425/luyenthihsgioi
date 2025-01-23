#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("SIGNAL.INP");
    ofstream output("SIGNAL.OUT");

    int n, k;
    string signal;

    // Đọc dữ liệu từ file
    input >> n >> k;
    input >> signal;

    // Tính số lần quay thực sự cần (k modulo n)
    k = k % n;

    // Phục hồi tín hiệu gốc
    string original_signal = signal.substr(n - k) + signal.substr(0, n - k);

    // Ghi kết quả ra file
    output << original_signal;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
