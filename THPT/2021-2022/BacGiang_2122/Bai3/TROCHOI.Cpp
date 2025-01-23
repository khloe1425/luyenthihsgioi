#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // Đọc dữ liệu từ tệp
    freopen("TROCHOI.INP", "r", stdin);
    freopen("TROCHOI.OUT", "w", stdout);

    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // Tìm giá trị nhỏ nhất của một lượt chơi lớn hơn 0
    int minResult = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = A[i] + B[j];
            if (sum > 0) {
                minResult = min(minResult, sum);
            }
        }
    }

    // Kiểm tra nếu không có giá trị hợp lệ
    if (minResult == INT_MAX) {
        cout << "0" << endl;
    } else {
        cout << minResult << endl;
    }

    return 0;
}
