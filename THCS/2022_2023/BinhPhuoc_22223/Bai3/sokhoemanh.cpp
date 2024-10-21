#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Hàm tính tổng các ước thực sự của n
int tong_uoc_thuc_su(int n) {
    int tong = 1; // Bắt đầu với 1 vì 1 là ước của mọi số (ngoại trừ chính số đó)
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            if (i == n / i) {
                tong += i; // Nếu i là căn bậc 2 của n, chỉ thêm 1 lần
            } else {
                tong += i + (n / i); // Thêm cả i và n/i
            }
        }
    }
    return tong;
}

// Hàm kiểm tra số khỏe mạnh
bool la_so_khoe_manh(int n) {
    return tong_uoc_thuc_su(n) > n;
}

int main() {
    // Đọc dữ liệu từ file sokhoemanh.inp
    ifstream infile("sokhoemanh.inp");
    int a, b;
    infile >> a >> b;
    infile.close();

    // Đếm số lượng số khỏe mạnh trong đoạn [a, b]
    int dem_so_khoe_manh = 0;
    for (int n = a; n <= b; ++n) {
        if (la_so_khoe_manh(n)) {
            ++dem_so_khoe_manh;
        }
    }

    // Ghi kết quả ra file sokhoemanh.out
    ofstream outfile("sokhoemanh.out");
    outfile << dem_so_khoe_manh << endl;
    outfile.close();

    return 0;
}
