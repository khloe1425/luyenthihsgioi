#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Mở file input và output
    ifstream infile("incr.inp");
    ofstream outfile("incr.out");

    // Đọc dữ liệu
    int n, d;
    infile >> n >> d;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        infile >> b[i];
    }

    int total_operations = 0;

    // Duyệt qua từng cặp phần tử liên tiếp
    for (int i = 1; i < n; ++i) {
        if (b[i] <= b[i - 1]) {
            // Tính số thao tác cần thiết
            int needed_increase = (b[i - 1] - b[i] + d) / d;
            total_operations += needed_increase;
            // Cập nhật giá trị mới của b[i]
            b[i] += needed_increase * d;
        }
    }

    // Ghi kết quả ra file output
    outfile << total_operations << endl;

    // Đóng file
    infile.close();
    outfile.close();

    return 0;
}
