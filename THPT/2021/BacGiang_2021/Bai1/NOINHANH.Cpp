#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream input("NOINHANH.INP");
    ofstream output("NOINHANH.OUT");

    int n;
    input >> n;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        input >> A[i];
    }

    vector<int> result; // Lưu các số mà An nói
    int current_sum = 0; // Tổng tích lũy

    // Xử lý để tính các số mà An nói
    for (int i = 0; i < n; ++i) {
        current_sum += A[i];
        if (i % 2 == 0) { // An nói ở vị trí lẻ (0-based: 0, 2, 4, ...)
            result.push_back(current_sum);
        }
    }

    // Ghi kết quả ra file
    for (int i = 0; i < result.size(); ++i) {
        output << result[i];
        if (i < result.size() - 1) {
            output << " ";
        }
    }
    output << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
