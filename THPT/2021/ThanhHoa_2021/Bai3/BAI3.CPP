#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("BAI3.INP");
    ofstream fout("BAI3.OUT");

    int N, K;
    fin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        fin >> a[i];
    }

    // Sắp xếp các món quà theo thứ tự tăng dần
    sort(a.begin(), a.end());

    long long totalCost = 0; // Tổng chi phí nhỏ nhất
    int i = 0;

    while (i < N) {
        totalCost += a[i]; // Chọn món quà đắt nhất trong đơn hàng hiện tại
        int j = i + 1;

        // Tìm món quà tiếp theo có chênh lệch giá ít nhất là K
        while (j < N && a[j] - a[i] < K) {
            j++;
        }

        i = j; // Bắt đầu đơn hàng mới từ vị trí j
    }

    fout << totalCost << "\n";

    fin.close();
    fout.close();

    return 0;
}
