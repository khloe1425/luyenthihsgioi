#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

// Hàm tạo tập hợp {u_k}
set<int> generateTriangleNumbers(int limit) {
    set<int> triangleNumbers;
    int k = 1, value = 1;
    while (value <= limit) {
        triangleNumbers.insert(value);
        k++;
        value += k; // u_k = u_{k-1} + k
    }
    return triangleNumbers;
}

int main() {
    // Đọc dữ liệu từ file MAXISEQ.INP
    ifstream inputFile("MAXISEQ.INP");
    ofstream outputFile("MAXISEQ.OUT");

    int n;
    inputFile >> n; // Số lượng phần tử trong dãy

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        inputFile >> a[i]; // Nhập các phần tử của dãy
    }

    // Tạo tập {u_k} gồm các số tam giác Pascal <= 10^8
    set<int> triangleNumbers = generateTriangleNumbers(100000000);

    // Debug: In tập số tam giác Pascal
    cout << "Triangle Numbers: ";
    for (int num : triangleNumbers) {
        cout << num << " ";
    }
    cout << endl;

    // Lọc các phần tử thuộc {u_k}
    vector<int> filtered;
    for (int i = 0; i < n; i++) {
        if (triangleNumbers.count(a[i])) {
            filtered.push_back(a[i]);
        }
    }

    // Debug: In các phần tử sau khi lọc
    cout << "Filtered elements: ";
    for (int num : filtered) {
        cout << num << " ";
    }
    cout << endl;

    // Nếu không có phần tử nào trong {u_k}, kết quả là 0
    if (filtered.empty()) {
        outputFile << 0 << endl;
        return 0;
    }

    // Tìm dãy con không giảm dài nhất trong filtered
    int m = filtered.size();
    vector<int> dp(m, 1);

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (filtered[j] <= filtered[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Debug: In mảng dp
    cout << "DP array: ";
    for (int val : dp) {
        cout << val << " ";
    }
    cout << endl;

    // Tìm giá trị lớn nhất trong dp
    int maxLength = *max_element(dp.begin(), dp.end());

    // Ghi kết quả ra file MAXISEQ.OUT
    outputFile << maxLength << endl;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
