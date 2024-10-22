#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;  // Nhập số lượng test cases
    vector<long long> results(T);  // Danh sách lưu kết quả

    for (int i = 0; i < T; ++i) {
        long long N;
        cin >> N;  // Nhập số nguyên dương N
        results[i] = N * (N + 1) / 2;  // Tính tổng S(N)
    }

    // Xuất kết quả
    for (long long result : results) {
        cout << result << endl;
    }

    return 0;
}
