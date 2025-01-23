#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

// Hàm tính thời gian tối thiểu để nhóm vượt cầu
int calculateMinimumTime(int n, int m, vector<int>& r, string& bridge) {
    vector<int> validSections;

    // Lọc ra các đoạn cầu có thể đi qua
    for (int i = 0; i < m; i++) {
        if (bridge[i] == '0') {
            validSections.push_back(i);
        }
    }

    // Nếu không có đoạn cầu nào hợp lệ
    if (validSections.empty()) {
        return -1;
    }

    // Sắp xếp tốc độ của nhóm người
    sort(r.begin(), r.end());

    int totalTime = 0;

    // Chiến lược Greedy:
    while (n > 3) {
        // Trường hợp 1: Người nhanh nhất và chậm nhất
        int option1 = 2 * r[1] + r[0] + r[n - 1];

        // Trường hợp 2: Hai người nhanh nhất
        int option2 = 2 * r[0] + r[n - 2] + r[n - 1];

        totalTime += min(option1, option2);

        n -= 2; // Loại bỏ 2 người nhanh nhất đã qua cầu
    }

    // Xử lý các trường hợp còn lại
    if (n == 3) {
        totalTime += r[0] + r[1] + r[2];
    } else if (n == 2) {
        totalTime += r[1];
    } else if (n == 1) {
        totalTime += r[0];
    }

    return totalTime;
}

int main() {
    ifstream fin("CROSS.INP");
    ofstream fout("CROSS.OUT");

    int n, m;
    fin >> n >> m;

    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        fin >> r[i];
    }

    string bridge;
    fin >> bridge;

    int result = calculateMinimumTime(n, m, r, bridge);

    fout << result << endl;

    fin.close();
    fout.close();

    return 0;
}
