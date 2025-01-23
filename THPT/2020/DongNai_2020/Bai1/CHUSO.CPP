#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Hàm tìm chữ số cuối cùng của m^n
int lastDigit(int m, int n) {
    if (n == 0) return 1; // Trường hợp đặc biệt: m^0 = 1 với mọi m

    // Lấy chữ số cuối cùng của m
    int last = m % 10;

    // Xác định chu kỳ của chữ số cuối cùng
    vector<int> cycle;
    int current = last;
    do {
        cycle.push_back(current);
        current = (current * last) % 10;
    } while (current != last);

    // Sử dụng chu kỳ để tìm kết quả
    int cycleLength = cycle.size();
    int index = (n - 1) % cycleLength; // Vị trí trong chu kỳ
    return cycle[index];
}

int main() {
    ifstream input("CHUSO.INP");
    ofstream output("CHUSO.OUT");

    int m, n;
    input >> m >> n;

    // Tính chữ số cuối cùng
    int result = lastDigit(m, n);

    // Ghi kết quả ra file
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
