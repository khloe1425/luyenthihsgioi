#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm tính thời gian sớm nhất hoàn thành công việc trên một loại máy
int calculateTime(int N, int machineCount, int processingTime) {
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap để quản lý thời gian rảnh của các máy
    for (int i = 0; i < machineCount; ++i) {
        pq.push(0); // Ban đầu, tất cả các máy đều rảnh tại thời điểm 0
    }

    for (int i = 0; i < N; ++i) {
        int earliest = pq.top(); // Lấy thời gian rảnh sớm nhất của một máy
        pq.pop();
        pq.push(earliest + processingTime); // Cập nhật thời gian rảnh sau khi xử lý một sản phẩm
    }

    // Thời gian lớn nhất trong hàng đợi là thời gian hoàn thành cuối cùng
    int result = 0;
    while (!pq.empty()) {
        result = max(result, pq.top());
        pq.pop();
    }
    return result;
}

int main() {
    ifstream inputFile("SANXUAT.INP");
    ofstream outputFile("SANXUAT.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    // Đọc dữ liệu từ file
    int N, M1, T1, M2, T2;
    inputFile >> N >> M1 >> T1 >> M2 >> T2;

    // Tính thời gian hoàn thành nguyên công A
    int timeA = calculateTime(N, M1, T1);

    // Tính thời gian hoàn thành nguyên công B
    int timeB = calculateTime(N, M2, T2);

    // Ghi kết quả ra file
    outputFile << timeA << endl; // Thời gian hoàn thành nguyên công A
    outputFile << max(timeA, timeB) << endl; // Thời gian hoàn thành cả hai nguyên công

    inputFile.close();
    outputFile.close();
    return 0;
}
