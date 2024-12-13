#include <iostream>
#include <fstream>
#include <unordered_map>
#include <limits>
using namespace std;

int main() {
    ifstream input("HEALTH.INP");
    ofstream output("HEALTH.OUT");

    int N;
    input >> N;

    unordered_map<int, int> healthCount; // Đếm tần suất mã số sức khỏe
    int health;

    // Đọc mã số sức khỏe và đếm tần suất
    for (int i = 0; i < N; ++i) {
        input >> health;
        healthCount[health]++;
    }

    int minHealth = numeric_limits<int>::max();
    bool found = false;

    // Duyệt qua các mã số sức khỏe để tìm mã số nhỏ nhất không trùng lặp
    for (const auto &pair : healthCount) {
        if (pair.second == 1 && pair.first < minHealth) { // Nếu mã chỉ xuất hiện 1 lần và nhỏ hơn min
            minHealth = pair.first;
            found = true;
        }
    }

    // Kiểm tra kết quả
    if (found) {
        output << minHealth << endl; // Ghi mã số nhỏ nhất không trùng lặp
    } else {
        output << -1 << endl; // Nếu không có mã nào thỏa mãn
    }

    input.close();
    output.close();

    return 0;
}
