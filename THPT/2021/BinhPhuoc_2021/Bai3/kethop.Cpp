#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream input("kethop.inp");
    ofstream output("kethop.out");

    int x, y, z, n;
    input >> x >> y >> z >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        input >> a[i];
    }

    // Biến lưu giá trị lớn nhất của T
    long long maxT = LLONG_MIN;

    // Duyệt qua tất cả các bộ ba (i, j, k)
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                long long T = 1LL * x * a[i] + 1LL * y * a[j] + 1LL * z * a[k];
                maxT = max(maxT, T);
            }
        }
    }

    // Ghi kết quả ra file
    output << maxT << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
