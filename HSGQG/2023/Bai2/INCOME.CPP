#include <bits/stdc++.h>
using namespace std;

int main() {
    // Đọc dữ liệu từ file INCOME.INP
    ifstream inputFile("INCOME.INP");
    ofstream outputFile("INCOME.OUT");

    int N;
    inputFile >> N;

    vector<long long> income(N);
    vector<pair<int, int>> ranges(N);

    for (int i = 0; i < N; ++i) {
        inputFile >> income[i];
    }

    for (int i = 0; i < N; ++i) {
        inputFile >> ranges[i].first >> ranges[i].second;
        // Chuyển về 0-based index
        ranges[i].first--;
        ranges[i].second--;
    }

    inputFile.close();

    // Mô phỏng qua từng năm
    int years = 0;
    while (true) {
        vector<long long> newIncome = income;
        bool isStable = true;

        // Tính toán thu nhập mới cho từng hộ
        for (int i = 0; i < N; ++i) {
            long long maxIncome = income[i];
            for (int j = ranges[i].first; j <= ranges[i].second; ++j) {
                maxIncome = max(maxIncome, income[j]);
            }
            newIncome[i] = maxIncome;
            if (newIncome[i] != income[i]) {
                isStable = false; // Có sự thay đổi
            }
        }

        // Nếu không có sự thay đổi, dừng lại
        if (isStable) break;

        // Cập nhật thu nhập mới
        income = newIncome;
        years++;
    }

    // Ghi kết quả ra file INCOME.OUT
    outputFile << years + 1 << endl;
    outputFile.close();

    return 0;
}
