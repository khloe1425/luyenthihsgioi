#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm tính tổng các chữ số của một số n
int tong_cac_chu_so(int n) {
    int tong = 0;
    while (n > 0) {
        tong += n % 10;
        n /= 10;
    }
    return tong;
}

int main() {
    // Mở file đầu vào
    ifstream infile("SIMILAR.INP");
    int l, r;
    infile >> l >> r;
    infile.close();

    // Từ điển lưu danh sách các số theo tổng chữ số
    unordered_map<int, vector<int>> tu_dien;

    // Duyệt qua tất cả các số từ l đến r
    for (int n = l; n <= r; ++n) {
        int tong_chu_so = tong_cac_chu_so(n);  // Tính tổng các chữ số
        tu_dien[tong_chu_so].push_back(n);     // Thêm số vào danh sách tương ứng
    }

    // Tìm hiệu lớn nhất
    int hieu_lon_nhat = 0;
    for (auto &entry : tu_dien) {
        vector<int> &ds = entry.second;
        if (ds.size() > 1) {  // Nếu có nhiều hơn 1 số có cùng tổng chữ số
            int max_val = *max_element(ds.begin(), ds.end());
            int min_val = *min_element(ds.begin(), ds.end());
            hieu_lon_nhat = max(hieu_lon_nhat, max_val - min_val);
        }
    }

    // Ghi kết quả ra file đầu ra
    ofstream outfile("SIMILAR.OUT");
    outfile << hieu_lon_nhat << endl;
    outfile.close();

    return 0;
}
