#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("VNI.INP");
    ofstream output("VNI.OUT");

    int N, Q;
    input >> N;

    vector<int> A(N + 1); // Giá cổ phiếu từ ngày 1 đến N
    for (int i = 1; i <= N; i++) {
        input >> A[i];
    }

    input >> Q;
    vector<int> queries(Q); // Các truy vấn
    for (int i = 0; i < Q; i++) {
        input >> queries[i];
    }

    // Tính mảng maxProfit từ ngày i đến N
    vector<int> maxProfit(N + 1, 0);
    int maxPrice = A[N]; // Giá cao nhất từ ngày N trở về sau

    // Tính lợi nhuận lớn nhất từ mỗi ngày đến N
    for (int i = N - 1; i >= 1; i--) {
        maxProfit[i] = max(maxProfit[i + 1], maxPrice - A[i]);
        maxPrice = max(maxPrice, A[i]); // Cập nhật giá cao nhất
    }

    // Xử lý các truy vấn
    for (int i = 0; i < Q; i++) {
        int T = queries[i];
        if (T >= 1 && T <= N) {
            output << maxProfit[T] << endl; // Lợi nhuận tối đa từ ngày T
        } else {
            output << 0 << endl; // Ngày không hợp lệ
        }
    }

    input.close();
    output.close();

    return 0;
}
