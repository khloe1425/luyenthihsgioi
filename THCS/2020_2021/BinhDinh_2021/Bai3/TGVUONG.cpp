#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    // Mở file input và output
    freopen("TGVUONG.INP", "r", stdin);
    freopen("TGVUONG.OUT", "w", stdout);

    int M, N;
    cin >> M >> N;

    double maxArea = 0.0;

    // Duyệt các giá trị của c
    for (int c = 1; c <= N; ++c) {
        for (int b = 1; b < c; ++b) {
            int aSquared = c * c - b * b;
            int a = sqrt(aSquared);

            // Kiểm tra a phải là số nguyên dương và a^2 + b^2 = c^2
            if (a > 0 && a < b && a * a == aSquared) {
                int perimeter = a + b + c;

                // Kiểm tra tổng chu vi
                if (M <= perimeter && perimeter <= N) {
                    double area = 0.5 * a * b;
                    maxArea = max(maxArea, area);
                }
            }
        }
    }

    // Ghi kết quả
    if (maxArea > 0.0) {
        cout << fixed << setprecision(1) << maxArea << endl;
    } else {
        cout << "0.0" << endl;
    }

    return 0;
}
