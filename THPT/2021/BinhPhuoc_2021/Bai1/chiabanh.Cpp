#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream input("chiabanh.inp");
    ofstream output("chiabanh.out");

    long long N;
    input >> N;

    vector<pair<long long, long long>> results;

    // Tìm tất cả các cặp (số hộp, số bánh/hộp)
    for (long long k = 1; k * k <= N; ++k) {
        if (N % k == 0) {
            results.emplace_back(k, N / k);
            if (k != N / k) { // Tránh lưu hai lần nếu k == N/k
                results.emplace_back(N / k, k);
            }
        }
    }

    // Sắp xếp các cặp theo số hộp tăng dần
    sort(results.begin(), results.end());

    // Ghi kết quả ra file
    for (auto &pair : results) {
        output << pair.first << " " << pair.second << endl;
    }

    // Đóng file
    input.close();
    output.close();

    return 0;
}
