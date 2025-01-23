#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ifstream inputFile("SDEV.INP");
    ofstream outputFile("SDEV.OUT");

    int N;
    ll K;
    inputFile >> N >> K;

    // Hàng đợi ưu tiên để lưu K giá trị lớn nhất
    priority_queue<ll, vector<ll>, greater<ll>> minHeap;

    for (int i = 0; i < N; ++i) {
        int L, B, R, T;
        inputFile >> L >> B >> R >> T;

        // Thêm các điểm trên cạnh trái và phải
        for (int y = B; y <= T; ++y) {
            ll costLeft = L + y; // Cạnh trái
            ll costRight = R + y; // Cạnh phải

            // Thêm vào minHeap, chỉ giữ K phần tử lớn nhất
            minHeap.push(costLeft);
            if (minHeap.size() > K) minHeap.pop();

            minHeap.push(costRight);
            if (minHeap.size() > K) minHeap.pop();
        }

        // Thêm các điểm trên cạnh dưới và trên
        for (int x = L; x <= R; ++x) {
            ll costBottom = x + B; // Cạnh dưới
            ll costTop = x + T;    // Cạnh trên

            // Thêm vào minHeap, chỉ giữ K phần tử lớn nhất
            minHeap.push(costBottom);
            if (minHeap.size() > K) minHeap.pop();

            minHeap.push(costTop);
            if (minHeap.size() > K) minHeap.pop();
        }
    }

    // Tính tổng K giá trị lớn nhất
    ll maxCost = 0;
    while (!minHeap.empty()) {
        maxCost += minHeap.top();
        minHeap.pop();
    }

    outputFile << maxCost << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
