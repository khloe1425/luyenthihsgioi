#include <iostream>
#include <fstream>

using namespace std;

// Hàm tính tổ hợp C(k, r)
long long calculate_combination(int k, int r) {
    if (r > k - r) r = k - r; // C(k, r) = C(k, k-r)
    long long result = 1;
    for (int i = 1; i <= r; ++i) {
        result = result * (k - i + 1) / i;
    }
    return result;
}

int main() {
    // Đọc dữ liệu từ file
    ifstream input("DUONGDI.INP");
    ofstream output("DUONGDI.OUT");

    int n;
    input >> n;

    // Tính số đường đi
    long long result = calculate_combination(2 * n - 2, n - 1);

    // Ghi kết quả ra file
    output << result << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
