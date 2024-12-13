#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Mở file input và output
    freopen("DAYSO.INP", "r", stdin);
    freopen("DAYSO.OUT", "w", stdout);

    int N;
    cin >> N;
    vector<int> T(N), P(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    // Phục hồi dãy P
    for (int i = N; i >= 1; --i) { // Duyệt từ số lớn nhất đến nhỏ nhất
        int count = 0;             // Đếm số vị trí trống đã duyệt
        for (int j = 0; j < N; ++j) {
            if (P[j] == 0) count++; // Vị trí trống
            if (count == T[i - 1] + 1) { // Khi tìm được vị trí đúng
                P[j] = i;                // Chèn số vào
                break;
            }
        }
    }

    // Xuất dãy P
    for (int i = 0; i < N; ++i) {
        cout << P[i] << " ";
    }
    cout << endl;

    return 0;
}
