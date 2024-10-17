#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream infile("Moon.INP");
    std::ofstream outfile("Moon.OUT");

    int n, a; // số học sinh và số bánh trung thu
    infile >> n >> a;

    // Tạo vector để lưu số bánh trung thu mà mỗi học sinh nhận
    std::vector<int> cakes(n, 0);

    // Gán số bánh cho An (vị trí 0)
    cakes[0] = a;

    // Phân phối bánh cho học sinh bên trái
    for (int i = 1; i < n; ++i) {
        if (cakes[i - 1] > 0) {
            cakes[i] = cakes[i - 1] - 1; // Mỗi bạn bên trái nhận ít hơn một chiếc
        }
    }

    // Phân phối bánh cho học sinh bên phải
    for (int i = n - 2; i >= 0; --i) {
        if (cakes[i + 1] > 0) {
            cakes[i] = std::max(cakes[i], cakes[i + 1] - 1); // Đảm bảo không ai bên trái ít hơn
        }
    }

    // Tính số bánh tối đa mà An có thể nhận (tức là số bánh ở vị trí 0)
    outfile << cakes[0] << std::endl;

    infile.close();
    outfile.close();
    return 0;
}
