#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input_path = "QUA.INP";
    string output_path = "QUA.OUT";

    // Mở tệp nhập
    ifstream infile(input_path);
    if (!infile.is_open()) {
        cerr << "Không thể mở tệp: " << input_path << endl;
        return 1;
    }

    int n, k;
    infile >> n >> k;

    // Tạo vector để lưu giá trị quà
    vector<int> values(n);

    // Đọc giá trị của từng phần quà
    for (int i = 0; i < n; ++i) {
        infile >> values[i];
    }

    infile.close();

    // Sắp xếp giá trị quà theo thứ tự giảm dần
    sort(values.begin(), values.end(), greater<int>());

    // Tính tổng giá trị lớn nhất của k phần quà
    int max_value = 0;
    for (int i = 0; i < k; ++i) {
        max_value += values[i];
    }

    // Mở tệp xuất
    ofstream outfile(output_path);
    if (!outfile.is_open()) {
        cerr << "Không thể mở tệp: " << output_path << endl;
        return 1;
    }

    outfile << max_value << endl;

    outfile.close();

    return 0;
}
