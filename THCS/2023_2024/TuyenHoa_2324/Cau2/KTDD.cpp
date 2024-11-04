#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>

int main() {
    // Đọc dữ liệu từ file KTDD.INP
    std::ifstream infile("KTDD.INP");
    std::string st;
    std::getline(infile, st);
    infile.close();

    // Sử dụng set để tự động loại bỏ các ký tự trùng lặp
    std::set<char> representative_set(st.begin(), st.end());

    // Ghi kết quả vào file KTDD.OUT
    std::ofstream outfile("KTDD.OUT");
    for (auto it = representative_set.begin(); it != representative_set.end(); ++it) {
        if (it != representative_set.begin()) {
            outfile << " "; // Thêm khoảng trắng giữa các ký tự
        }
        outfile << *it; // Ghi ký tự vào file
    }
    outfile << std::endl;
    outfile.close();

    return 0;
}
