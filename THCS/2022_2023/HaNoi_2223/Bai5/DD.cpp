#include <bits/stdc++.h>
using namespace std;

int main() {
    // Mở tệp đầu vào và đầu ra
    ifstream inp("DD.INP");
    ofstream out("DD.OUT");

    int n;
    inp >> n; // Đọc số nguyên dương N
    vector<int> A(n); // Khởi tạo mảng A
    for (int i = 0; i < n; ++i) {
        inp >> A[i]; // Đọc các phần tử của A
    }
    inp.close();

    long long count = 0; // Biến đếm số dãy con đẹp

    for (int i = 0; i < n; ++i) {
        int min_val = A[i]; // Giá trị nhỏ nhất trong dãy con
        int max_val = A[i]; // Giá trị lớn nhất trong dãy con

        for (int j = i; j < n; ++j) {
            min_val = min(min_val, A[j]); // Cập nhật giá trị nhỏ nhất
            max_val = max(max_val, A[j]); // Cập nhật giá trị lớn nhất

            // Kiểm tra điều kiện để là dãy đẹp
            if (max_val - min_val == j - i) {
                count++; // Tăng số dãy con đẹp
            }
        }
    }

    // Ghi kết quả ra tệp
    out << count << endl;
    out.close();

    return 0;
}
