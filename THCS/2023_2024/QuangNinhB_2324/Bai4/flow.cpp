#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Flower {
    long long a; // Độ vui vẻ khi mua 1 bông
    long long b; // Độ vui vẻ tăng thêm cho mỗi bông tiếp theo
};

// Hàm tính độ vui vẻ tối đa
long long maxHappiness(int n, long long m, vector<Flower>& flowers) {
    // Sắp xếp các loại hoa theo b_i giảm dần
    sort(flowers.begin(), flowers.end(), [](const Flower& f1, const Flower& f2) {
        return f1.b > f2.b; 
    });

    long long totalHappiness = 0; // Tổng độ vui vẻ
    long long remaining = m; // Số bông hoa còn lại cần mua

    for (const auto& flower : flowers) {
        if (remaining <= 0) break; // Nếu đã mua đủ bông hoa

        // Mua ít nhất 1 bông hoa
        totalHappiness += flower.a; // Độ vui vẻ khi mua 1 bông
        remaining--; // Giảm số bông hoa cần mua

        // Nếu còn đủ bông hoa cần mua
        while (remaining > 0) {
            totalHappiness += flower.b; // Thêm độ vui vẻ từ bông tiếp theo
            remaining--; // Giảm số bông hoa cần mua
        }
    }

    return totalHappiness;
}

int main() {
    // Đọc dữ liệu từ file
    ifstream infile("flow.inp");
    int n;
    long long m;
    infile >> n >> m; // Đọc n và m

    vector<Flower> flowers(n); // Mảng chứa các loại hoa

    // Đọc thông tin các loại hoa
    for (int i = 0; i < n; ++i) {
        infile >> flowers[i].a >> flowers[i].b;
    }
    infile.close();

    // Tính độ vui vẻ tối đa
    long long result = maxHappiness(n, m, flowers);

    // Ghi kết quả ra file
    ofstream outfile("flow.out");
    outfile << result << endl;
    outfile.close();

    return 0;
}
