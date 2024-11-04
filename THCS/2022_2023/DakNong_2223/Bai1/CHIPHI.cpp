#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Đọc dữ liệu từ file CHIPHI.INP
    ifstream input("CHIPHI.INP");
    int n, x;
    input >> n >> x;
    input.close();

    // Tính số ghế đá
    int num_benches;
    if (n % 2 == 0) {
        num_benches = n / 2;  // Nếu n chẵn
    } else {
        num_benches = (n / 2) + 1;  // Nếu n lẻ
    }

    // Tính tổng chi phí
    long long total_cost = static_cast<long long>(num_benches) * x;

    // Ghi kết quả ra file CHIPHI.OUT
    ofstream output("CHIPHI.OUT");
    output << total_cost << endl;
    output.close();

    return 0;
}
