#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Hàm tính tổ hợp C(k, 3) = k * (k - 1) * (k - 2) / 6
long long combination_3(int k) {
    if (k < 3) return 0;
    return (1LL * k * (k - 1) * (k - 2)) / 6;
}

// Hàm chính để tìm số lượng tam giác đều có cạnh lớn nhất
int max_equilateral_triangles(const std::vector<int>& lengths) {
    int n = lengths.size();

    // Đếm số lần xuất hiện của mỗi độ dài thanh gỗ
    std::vector<int> count(1000001, 0);
    for (int length : lengths) {
        count[length]++;
    }

    // Tìm độ dài lớn nhất có ít nhất 3 thanh gỗ
    for (int i = 1000000; i >= 1; --i) {
        if (count[i] >= 3) {
            return combination_3(count[i]);
        }
    }

    return 0; // Không thể tạo tam giác đều nào
}

int main() {
    std::ifstream infile("MAXCETRI.INP");
    std::ofstream outfile("MAXCETRI.OUT");

    // Kiểm tra xem file đầu vào và đầu ra có mở thành công không
    if (!infile || !outfile) {
        std::cerr << "Lỗi mở file đầu vào hoặc đầu ra!" << std::endl;
        return 1;
    }

    int n;
    infile >> n; // Đọc số lượng thanh gỗ

    std::vector<int> lengths(n);
    for (int i = 0; i < n; ++i) {
        infile >> lengths[i]; // Đọc độ dài của từng thanh gỗ
    }

    // Sắp xếp các độ dài thanh gỗ
    std::sort(lengths.begin(), lengths.end());

    // Tìm số lượng tam giác đều có cạnh lớn nhất và ghi kết quả vào file
    int result = max_equilateral_triangles(lengths);
    outfile << result << std::endl;

    infile.close();
    outfile.close();

    return 0;
}
