#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    // Mở file CAYXANH.INP để đọc dữ liệu
    ifstream input("CAYXANH.INP");
    ofstream output("CAYXANH.OUT");

    // Đọc n, l, m
    int n;
    long long l, m;
    input >> n >> l >> m;

    // Khởi tạo biến đếm số cây thỏa mãn điều kiện
    int count = 0;
    long long height;

    // Duyệt qua từng chiều cao cây
    for (int i = 0; i < n; i++) {
        input >> height;
        if (abs(height - l) <= m) {
            count++;
        }
    }

    // Ghi kết quả ra file CAYXANH.OUT
    output << count;

    // Đóng các file
    input.close();
    output.close();

    return 0;
}
