#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream infile("CDIV.INP");
    int N;
    infile >> N; // Số phần tử trong mảng

    vector<int> count(1000001, 0); // Mảng đếm số lần xuất hiện của từng số
    int a;

    // Đếm số lần xuất hiện của từng số trong mảng
    for (int i = 0; i < N; ++i) {
        infile >> a;
        count[a]++;
    }
    infile.close();

    // Tìm GCD lớn nhất
    for (int g = 1000000; g >= 1; --g) {
        int sum = 0; // Biến đếm số bội của g
        // Kiểm tra các bội của g
        for (int j = g; j <= 1000000; j += g) {
            sum += count[j];
            if (sum >= 2) { // Nếu có ít nhất 2 số là bội của g
                ofstream outfile("CDIV.OUT");
                outfile << g << endl; // Ghi GCD lớn nhất ra file
                outfile.close();
                return 0;
            }
        }
    }

    return 0;
}
