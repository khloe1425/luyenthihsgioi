#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm kiểm tra một số có phải là số nguyên tố hay không
bool la_so_nguyen_to(int n) {
    if (n < 2) return false; // Số nhỏ hơn 2 không phải là số nguyên tố
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // Đọc dữ liệu từ file nguyento.inp
    ifstream infile("nguyento.inp");
    int a, b;
    infile >> a >> b;
    infile.close();

    // Đếm số lượng số nguyên tố trong đoạn [a, b]
    int dem_so_nguyen_to = 0;
    for (int n = a; n <= b; ++n) {
        if (la_so_nguyen_to(n)) {
            ++dem_so_nguyen_to;
        }
    }

    // Ghi kết quả ra file nguyento.out
    ofstream outfile("nguyento.out");
    outfile << dem_so_nguyen_to << endl;
    outfile.close();

    return 0;
}
