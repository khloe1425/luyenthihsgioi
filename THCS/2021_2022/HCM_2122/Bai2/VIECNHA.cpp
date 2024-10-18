#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    // Đọc dữ liệu từ file VIECNHA.INP
    ifstream inputFile("VIECNHA.INP");
    ofstream outputFile("VIECNHA.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    int T, C;
    inputFile >> T >> C;

    // Danh sách thời gian cho các công việc
    vector<int> tasks(C);
    for (int i = 0; i < C; i++) {
        inputFile >> tasks[i];
    }

    // Sắp xếp thời gian các công việc theo thứ tự tăng dần
    sort(tasks.begin(), tasks.end());

    // Khởi tạo biến đếm và tổng thời gian
    int totalTime = 0;
    int count = 0;

    // Thực hiện các công việc cho đến khi hết thời gian
    for (int task : tasks) {
        if (totalTime + task <= T) {
            totalTime += task;
            count++;
        } else {
            break;
        }
    }

    // Ghi kết quả ra file VIECNHA.OUT
    outputFile << count << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}