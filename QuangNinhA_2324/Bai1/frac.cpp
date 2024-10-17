#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <fstream>  // Thêm thư viện này

using namespace std;

// Hàm tính tổng phân số
double calculateFraction(double x, double y, double z, double w) {
    return (x / y) + (z / w);
}

// Hàm tìm thứ tự tối ưu
vector<int> minFractionOrder(int a, int b, int c, int d) {
    vector<int> numbers = {a, b, c, d};
    vector<int> bestOrder;
    double minValue = numeric_limits<double>::infinity();

    // Duyệt qua tất cả các hoán vị
    do {
        int x = numbers[0];
        int y = numbers[1];
        int z = numbers[2];
        int w = numbers[3];

        // Tính tổng phân số
        double totalValue = calculateFraction(x, y, z, w);

        if (totalValue < minValue) {
            minValue = totalValue;
            bestOrder = {x, y, z, w};
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return bestOrder;
}

int main() {
    // Đọc dữ liệu từ tệp
    ifstream input("frac.inp");
    ofstream output("frac.out");

    int a, b, c, d;
    input >> a >> b >> c >> d;

    // Tìm thứ tự tối ưu
    vector<int> result = minFractionOrder(a, b, c, d);

    // Ghi kết quả ra tệp
    for (int i = 0; i < result.size(); i++) {
        output << result[i] << (i < result.size() - 1 ? " " : "");
    }
    output << endl;

    return 0;
}
