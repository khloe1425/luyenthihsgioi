#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    ifstream input("FESTIVAL.INP");
    ofstream output("FESTIVAL.OUT");

    int n;
    input >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        input >> h[i];
    }

    vector<int> incr_left(n, 1), decr_left(n, 1), incr_right(n, 1), decr_right(n, 1);

    // Tính các đoạn tăng và giảm từ trái qua
    for (int i = 1; i < n; ++i) {
        if (h[i] > h[i - 1]) {
            incr_left[i] = incr_left[i - 1] + 1;
        }
        if (h[i] < h[i - 1]) {
            decr_left[i] = decr_left[i - 1] + 1;
        }
    }

    // Tính các đoạn tăng và giảm từ phải qua
    for (int i = n - 2; i >= 0; --i) {
        if (h[i] > h[i + 1]) {
            incr_right[i] = incr_right[i + 1] + 1;
        }
        if (h[i] < h[i + 1]) {
            decr_right[i] = decr_right[i + 1] + 1;
        }
    }

    int max_magnificence = 0;

    // Tìm các đoạn tạo thành chữ M
    for (int i = 1; i < n - 2; ++i) { // Chọn điểm kết thúc đoạn đầu tiên
        for (int j = i + 1; j < n - 1; ++j) { // Chọn điểm bắt đầu đoạn cuối cùng
            if (incr_left[i] >= 2 && decr_left[i] >= 1 &&
                incr_right[j] >= 2 && decr_right[j] >= 1) {
                int current_magnificence = incr_left[i] + decr_left[i] + incr_right[j] + decr_right[j];
                max_magnificence = max(max_magnificence, current_magnificence);
            }
        }
    }

    output << max_magnificence << endl;

    input.close();
    output.close();

    return 0;
}
