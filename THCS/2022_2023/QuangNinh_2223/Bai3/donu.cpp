#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Mở file input và output
    ifstream infile("donu.inp");
    ofstream outfile("donu.out");

    // Đọc dữ liệu
    int n, k;
    infile >> n >> k;
    string s;
    infile >> s;

    // Khởi tạo biến để lưu kết quả và các chỉ số cho thuật toán two-pointer
    int max_time = 0, left = 0, zeros_count = 0;

    // Duyệt qua xâu s với thuật toán two-pointer
    for (int right = 0; right < n; ++right) {
        if (s[right] == '0') {
            zeros_count++;
        }

        // Nếu số lượng '0' trong đoạn vượt quá k, dịch con trỏ trái (left)
        while (zeros_count > k) {
            if (s[left] == '0') {
                zeros_count--;
            }
            left++;
        }

        // Cập nhật giá trị time lớn nhất
        max_time = max(max_time, right - left + 1);
    }

    // Ghi kết quả ra file output
    outfile << max_time << endl;

    return 0;
}
