#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    ifstream fin("MOVE.INP");
    ofstream fout("MOVE.OUT");

    int n;
    fin >> n;

    vector<int> c(n), t(n);

    // Đọc vị trí cột và thời gian di chuyển
    for (int i = 0; i < n; i++) {
        fin >> c[i] >> t[i];
    }

    int min_time = INT_MAX;

    // Duyệt qua từng cột làm cột mục tiêu
    for (int target = 1; target <= 100; target++) {
        int total_time = 0;

        for (int i = 0; i < n; i++) {
            total_time = max(total_time, abs(c[i] - target) * t[i]);
        }

        min_time = min(min_time, total_time);
    }

    fout << min_time << endl;

    fin.close();
    fout.close();

    return 0;
}
