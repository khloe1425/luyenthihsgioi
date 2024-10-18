#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long max_rectangle_area(vector<int>& lengths) {
    unordered_map<int, int> count;  // Đếm số lượng que củi theo độ dài

    // Đếm số lượng các độ dài củi
    for (int length : lengths) {
        count[length]++;
    }

    vector<long long> sides;  // Lưu các độ dài có thể tạo thành cạnh
    // Lọc ra các độ dài có ít nhất 2 que
    for (auto& entry : count) {
        int length = entry.first;
        int cnt = entry.second;

        if (cnt >= 4) {
            sides.push_back(length); // Nếu có >= 4 que, có thể tạo 2 cặp
        }
        if (cnt >= 2) {
            sides.push_back(length); // Nếu có >= 2 que, có thể tạo 1 cặp
        }
    }

    // Sắp xếp các độ dài
    sort(sides.rbegin(), sides.rend());  // Sắp xếp giảm dần

    // Tính diện tích lớn nhất
    long long max_area = 0;
    for (size_t i = 0; i + 1 < sides.size(); i++) {
        // Kiểm tra xem 2 cạnh liền kề có thể tạo thành hình chữ nhật
        long long area = sides[i] * sides[i + 1];
        max_area = max(max_area, area);
        // Nếu gặp 2 cạnh bằng nhau (có thể tạo thành 2 cặp), thì bỏ qua cạnh tiếp theo
        if (sides[i] == sides[i + 1]) {
            i++;  // Bỏ qua cạnh đã sử dụng
        }
    }

    return max_area;
}

int main() {
    int N;
    cout << "Nhập số nguyên N: ";
    cin >> N;

    vector<int> lengths(N);
    cout << "Nhập độ dài các que củi: ";
    for (int i = 0; i < N; i++) {
        cin >> lengths[i];
    }

    long long result = max_rectangle_area(lengths);

    cout << "Diện tích lớn nhất hình chữ nhật có thể tạo: " << result << endl;

    return 0;
}
