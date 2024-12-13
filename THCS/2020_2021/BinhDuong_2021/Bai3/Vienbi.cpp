#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Mở file input và output
    freopen("Vienbi.INP", "r", stdin);
    freopen("Vienbi.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<int> balls(n);
    for (int i = 0; i < n; ++i) {
        cin >> balls[i];
    }

    int total = 0; // Tổng số bi Bo thu thập được

    while (true) {
        // Tìm ô có nhiều bi nhất
        int maxIndex = -1, maxBalls = 0;
        for (int i = 0; i < n; ++i) {
            if (balls[i] > maxBalls) {
                maxBalls = balls[i];
                maxIndex = i;
            }
        }

        // Nếu không còn ô nào có bi, thoát vòng lặp
        if (maxBalls == 0) break;

        // Cộng bi từ ô được chọn vào tổng
        total += balls[maxIndex];
        balls[maxIndex] = 0; // Đặt ô này về 0 (đã lấy hết bi)

        // Giảm bi trong các ô khác
        for (int i = 0; i < n; ++i) {
            if (i != maxIndex && balls[i] > 0) {
                balls[i]--;
            }
        }
    }

    // Ghi kết quả ra file
    cout << total << endl;

    return 0;
}
