// BUILD.CPP
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream input("BUILD.INP");
    ofstream output("BUILD.OUT");

    int n;
    input >> n;

    vector<long long> ways(n + 1, 0); // Sử dụng vector để lưu số cách ghép

    // Khởi tạo điều kiện cơ sở
    ways[1] = 1;
    if (n >= 2) {
        ways[2] = 2;
    }

    // Tính số cách ghép bìa theo công thức đệ quy
    for (int i = 3; i <= n; ++i) {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    // Xuất kết quả
    for (int i = 1; i <= n; ++i) {
        output << i << ": " << ways[i] << endl;
    }

    input.close();
    output.close();

    return 0;
}
