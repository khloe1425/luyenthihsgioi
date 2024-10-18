#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    // Đọc dữ liệu từ tệp bai5.inp
    ifstream infile("bai5.inp");
    ofstream outfile("bai5.out");

    int n;
    infile >> n; // Đọc n
    vector<int> A(n);

    // Đọc dãy số A
    for (int i = 0; i < n; i++) {
        infile >> A[i];
    }

    // Sắp xếp dãy số A
    sort(A.begin(), A.end());

    int max_mod = 0; // Biến lưu giá trị lớn nhất của ai mod aj

    // Duyệt qua từng phần tử trong dãy đã sắp xếp
    for (int i = 1; i < n; i++) { // Bắt đầu từ 1 vì cần có aj
        for (int j = 0; j < i; j++) {
            // Tính ai mod aj
            int mod_value = A[i] % A[j];
            // Cập nhật giá trị lớn nhất
            if (mod_value > max_mod) {
                max_mod = mod_value;
            }
        }
    }

    // Ghi kết quả vào tệp bai5.out
    outfile << max_mod << endl;

    infile.close();
    outfile.close();

    return 0;
}
