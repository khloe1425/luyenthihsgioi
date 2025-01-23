#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream input("BWPOINTS.INP");
    ofstream output("BWPOINTS.OUT");

    int n;
    input >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        input >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        input >> b[i];
    }
    input.close();

    // Sắp xếp tọa độ các điểm đen và trắng
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Tính số đoạn thẳng không giao nhau tối đa
    int maxNonIntersectingSegments = n; // Luôn là n vì mỗi điểm đen nối với 1 điểm trắng

    // Ghi kết quả ra file
    output << maxNonIntersectingSegments << endl;
    output.close();

    return 0;
}
