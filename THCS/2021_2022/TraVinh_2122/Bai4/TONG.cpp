#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    ifstream input("TONG.INP");
    ofstream output("TONG.OUT");

    int n;
    input >> n; // Đọc số lượng phần tử

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        input >> arr[i]; // Đọc dãy số
    }

    // Khởi tạo biến để tìm tổng lớn nhất
    int maxSum = INT_MIN; // Tổng lớn nhất
    int currentSum = 0;   // Tổng hiện tại
    int start = 0, end = 0, tempStart = 0;

    for (int i = 0; i < n; ++i) {
        currentSum += arr[i];

        // Nếu tìm được tổng lớn hơn, cập nhật maxSum và vị trí
        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        // Nếu tổng hiện tại âm, khởi động lại tổng và cập nhật tempStart
        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }

    // Xuất kết quả ra file
    output << "Xau con co tong lon nhat: " << maxSum << endl;
    output << "Bat dau tu vi tri: " << start + 1 << endl;
    output << "Dai: " << end - start + 1 << endl;

    input.close();
    output.close();

    return 0;
}
