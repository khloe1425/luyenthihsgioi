#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip> // Để định dạng số thập phân

using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream input("SUMATION.INP");
    ofstream output("SUMATION.OUT");

    int N;
    input >> N;

    // Sử dụng hàng đợi ưu tiên (min-heap)
    priority_queue<double, vector<double>, greater<double>> minHeap;

    // Đọc các số và đưa vào heap
    for (int i = 0; i < N; ++i) {
        double num;
        input >> num;
        minHeap.push(num);
    }

    double totalCost = 0.0;

    // Tính toán tổng chi phí
    while (minHeap.size() > 1) {
        // Lấy hai phần tử nhỏ nhất
        double a = minHeap.top();
        minHeap.pop();
        double b = minHeap.top();
        minHeap.pop();

        // Tính tổng và chi phí
        double sum = a + b;
        double cost = 0.05 * sum; // 5% của tổng
        totalCost += cost;

        // Đưa tổng trở lại heap
        minHeap.push(sum);
    }

    // Ghi kết quả ra file
    output << fixed << setprecision(2) << totalCost << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
