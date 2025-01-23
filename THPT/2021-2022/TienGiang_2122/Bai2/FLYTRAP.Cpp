#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Hàm tính diện tích tam giác
double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
}

int main() {
    ifstream input("FLYTRAP.INP");
    ofstream output("FLYTRAP.OUT");

    // Đọc tọa độ tam giác
    double x1, y1, x2, y2, x3, y3;
    input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Đọc số ruồi
    int m;
    input >> m;

    int count = 0; // Đếm số ruồi nằm trong tam giác
    double ux, uy;

    // Tính diện tích tam giác lớn
    double area = triangleArea(x1, y1, x2, y2, x3, y3);

    for (int i = 0; i < m; ++i) {
        input >> ux >> uy;

        // Tính diện tích 3 tam giác nhỏ
        double area1 = triangleArea(ux, uy, x2, y2, x3, y3);
        double area2 = triangleArea(x1, y1, ux, uy, x3, y3);
        double area3 = triangleArea(x1, y1, x2, y2, ux, uy);

        // Kiểm tra nếu tổng diện tích bằng diện tích tam giác lớn
        if (fabs(area - (area1 + area2 + area3)) < 1e-9) {
            ++count;
        }
    }

    // Ghi kết quả ra file
    output << count << endl;

    input.close();
    output.close();
    return 0;
}
