#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

int main() {
    ifstream input("HCN.INP");
    ofstream output("HCN.OUT");

    int n;
    input >> n;

    // Khởi tạo giá trị min/max cho tọa độ
    int x_min = numeric_limits<int>::max();
    int x_max = numeric_limits<int>::min();
    int y_min = numeric_limits<int>::max();
    int y_max = numeric_limits<int>::min();

    for (int i = 0; i < n; i++) {
        int x, y;
        input >> x >> y;
        x_min = min(x_min, x);
        x_max = max(x_max, x);
        y_min = min(y_min, y);
        y_max = max(y_max, y);
    }

    // Tính diện tích
    long long area = static_cast<long long>(x_max - x_min) * (y_max - y_min);
    output << area << endl;

    input.close();
    output.close();

    return 0;
}
