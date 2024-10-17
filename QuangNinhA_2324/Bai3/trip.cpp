#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("trip.inp");
    ofstream output("trip.out");

    int n, q;
    input >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        input >> a[i];
    }

    vector<int> mins;

    // Tạo tất cả các bộ ba và tính min
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                mins.push_back(min(a[i], min(a[j], a[k])));
            }
        }
    }

    // Sắp xếp các giá trị min
    sort(mins.begin(), mins.end());

    // Xử lý truy vấn
    for (int i = 0; i < q; i++) {
        int k;
        input >> k;
        output << mins[k - 1] << endl; // k - 1 vì chỉ số bắt đầu từ 0
    }

    return 0;
}
