#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

// Hàm kiểm tra xem 4 cạnh có tạo thành tứ giác hợp lệ không
bool isValidQuadrilateral(int a, int b, int c, int d) {
    return (a + b > c && a + c > b && a + d > b && b + c > a && b + d > a && c + d > a);
}

// Hàm tính diện tích tứ giác theo công thức Brahmagupta
double calculateArea(int a, int b, int c, int d) {
    double p = (a + b + c + d) / 2.0; // Nửa chu vi
    return sqrt((p - a) * (p - b) * (p - c) * (p - d));
}

int main() {
    // Mở file input và output
    ifstream inputFile("DIENTICH.INP");
    ofstream outputFile("DIENTICH.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở tệp!" << endl;
        return 1;
    }

    int k;
    inputFile >> k;

    double maxArea = 0.0;

    // Duyệt tất cả các bộ (a, b, c, d) thỏa mãn a + b + c + d = k
    for (int a = 1; a <= k / 4; ++a) {
        for (int b = a; b <= (k - a) / 3; ++b) {
            for (int c = b; c <= (k - a - b) / 2; ++c) {
                int d = k - a - b - c;
                if (d < c) break;

                // Kiểm tra tứ giác hợp lệ
                if (isValidQuadrilateral(a, b, c, d)) {
                    double area = calculateArea(a, b, c, d);
                    maxArea = max(maxArea, area);
                }
            }
        }
    }

    // Ghi kết quả ra tệp
    if (maxArea == 0.0) {
        outputFile << "0" << endl;
    } else {
        outputFile << static_cast<int>(round(maxArea)) << endl; // Làm tròn kết quả chính xác
    }

    // Đóng tệp
    inputFile.close();
    outputFile.close();

    return 0;
}
