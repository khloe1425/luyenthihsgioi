#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream input("TONGCHAN.INP");
    ofstream output("TONGCHAN.OUT");

    int n;
    input >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        input >> a[i];
    }

    int maxSum = -1;       // Tổng lớn nhất
    int currentSum = 0;    // Tổng hiện tại
    int start = -1, end = -1; // Chỉ số bắt đầu và kết thúc của dãy con hiện tại
    int maxStart = -1, maxEnd = -1; // Chỉ số bắt đầu và kết thúc của dãy con lớn nhất đầu tiên

    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            // Nếu là số chẵn, thêm vào tổng dãy hiện tại
            if (currentSum == 0) {
                start = i; // Đánh dấu bắt đầu dãy
            }
            currentSum += a[i];
            end = i; // Cập nhật vị trí kết thúc
        } else {
            // Nếu gặp số lẻ, kiểm tra tổng dãy hiện tại
            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxStart = start;
                maxEnd = end;
            }
            // Reset dãy hiện tại
            currentSum = 0;
        }
    }

    // Kiểm tra dãy cuối cùng nếu dãy không bị ngắt
    if (currentSum > maxSum) {
        maxSum = currentSum;
        maxStart = start;
        maxEnd = end;
    }

    // Ghi kết quả
    if (maxSum == -1 || maxEnd - maxStart + 1 < 2) {
        output << -1 << endl; // Không có dãy chẵn thỏa mãn hoặc không đủ 2 phần tử
    } else {
        for (int i = maxStart; i <= maxEnd; ++i) {
            output << a[i] << " ";
        }
        output << endl;
    }

    input.close();
    output.close();

    return 0;
}
