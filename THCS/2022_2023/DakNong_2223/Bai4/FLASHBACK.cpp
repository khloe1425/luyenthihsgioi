#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Hàm tính số lượng cá thể virus sau k ngày
long long count_virus(int n, int k) {
    // Vector để lưu số lượng cá thể mỗi ngày
    vector<long long> virus(100001, 0);
    virus[0] = n; // Ngày 0 có n cá thể ở mức 1

    // Lặp qua từng ngày
    for (int day = 1; day <= k; ++day) {
        long long new_viruses = 0;
        // Tính số cá thể mới sinh ra trong ngày
        for (int level = 0; level < day; ++level) {
            new_viruses = (new_viruses + virus[level] * (level + 1)) % MOD;
        }
        // Cập nhật số lượng cá thể cho ngày tiếp theo
        for (int level = day; level >= 1; --level) {
            virus[level] = virus[level - 1];
        }
        virus[0] = new_viruses; // Cập nhật số lượng cá thể ở mức 1
    }

    // Tính tổng số cá thể
    long long total_virus = 0;
    for (int level = 0; level <= k; ++level) {
        total_virus = (total_virus + virus[level]) % MOD;
    }

    return total_virus;
}

int main() {
    // Đọc dữ liệu từ file FLASHBACK.INP
    ifstream input_file("FLASHBACK.INP");
    int n, k;

    if (input_file.is_open()) {
        input_file >> n >> k; // Đọc n và k
        input_file.close();
    } else {
        cerr << "Không thể mở file FLASHBACK.INP" << endl;
        return 1;
    }

    // Tính số lượng cá thể virus sau k ngày
    long long result = count_virus(n, k);

    // Ghi kết quả ra file FLASHBACK.OUT
    ofstream output_file("FLASHBACK.OUT");
    if (output_file.is_open()) {
        output_file << result << endl;
        output_file.close();
    } else {
        cerr << "Không thể mở file FLASHBACK.OUT" << endl;
        return 1;
    }

    return 0;
}
