#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// Hàm tính hệ số cách nhiệt tối đa
long long calculate_max_insulation(vector<int>& layers) {
    long long total = 0;
    int previous = 0; // Lớp trước đó

    for (size_t i = 0; i < layers.size(); i++) {
        // Thêm hệ số cách nhiệt của lớp hiện tại
        total += layers[i];

        // Tính độ chênh lệch với lớp trước
        if (i > 0) {
            if (layers[i] > previous) {
                total += (layers[i] - previous);
            }
        }

        // Cập nhật lớp trước
        previous = layers[i];
    }
    
    return total;
}

int main() {
    ifstream input("NHIET.INP");
    int N;
    
    // Đọc số lượng lớp cách nhiệt
    input >> N;

    vector<int> layers(N);
    
    // Đọc các hệ số cách nhiệt
    for (int i = 0; i < N; i++) {
        input >> layers[i];
    }

    // Đóng tệp
    input.close();

    // Sắp xếp các lớp cách nhiệt để đạt được hệ số cách nhiệt tối đa
    sort(layers.begin(), layers.end());

    // Tính tổng hệ số cách nhiệt tối đa
    long long max_insulation = calculate_max_insulation(layers);

    // Xuất kết quả ra màn hình
    cout << max_insulation << endl;

    return 0;
}
