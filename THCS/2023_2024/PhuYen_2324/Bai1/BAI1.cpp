#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Hàm để tính độ bền của một số nguyên không âm
int calculate_persistence(int n) {
    if (n < 10) {
        return 0; // Độ bền là 0 nếu số có một chữ số
    }

    int product = 1;
    while (n > 0) {
        product *= (n % 10); // Tính tích các chữ số
        n /= 10;
    }

    return calculate_persistence(product) + 1; // Đệ quy cộng thêm 1
}

int main() {
    ifstream infile("BAI1.INP"); // Mở file để đọc
    ofstream outfile("BAI1.OUT"); // Mở file để ghi

    if (!infile) {
        cerr << "Không thể mở file BAI1.INP" << endl;
        return 1;
    }

    vector<int> results;
    int n;

    // Đọc từng số từ file
    while (infile >> n) {
        int persistence = calculate_persistence(n); // Tính độ bền
        results.push_back(persistence); // Lưu kết quả
    }

    // Ghi kết quả ra file
    for (int result : results) {
        outfile << result << endl;
    }

    infile.close(); // Đóng file đọc
    outfile.close(); // Đóng file ghi

    return 0;
}
