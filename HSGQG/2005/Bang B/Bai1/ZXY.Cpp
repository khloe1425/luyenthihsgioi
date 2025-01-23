#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// Hàm kiểm tra nếu dung lượng hộp M có thể đóng gói tối đa k hộp
bool canPack(const vector<int>& weights, int n, int k, int M) {
    int currentSum = 0;
    int boxes = 1; // Bắt đầu với 1 hộp
    for (int i = 0; i < n; ++i) {
        if (weights[i] > M) return false; // Nếu có sản phẩm lớn hơn M, không thể đóng gói
        if (currentSum + weights[i] > M) {
            ++boxes; // Cần thêm 1 hộp
            currentSum = weights[i];
        } else {
            currentSum += weights[i];
        }
        if (boxes > k) return false; // Nếu vượt quá số hộp k, không hợp lệ
    }
    return true;
}

int main() {
    // Đọc file input
    ifstream inputFile("ZXY.INP");
    ofstream outputFile("ZXY.OUT");

    int n, k;
    inputFile >> n >> k;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> weights[i];
    }
    inputFile.close();

    // Tìm kiếm nhị phân giá trị tối thiểu của M
    int left = 1, right = 30000 * n, result = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPack(weights, n, k, mid)) {
            result = mid; // Lưu giá trị M hiện tại
            right = mid - 1; // Thử tìm giá trị nhỏ hơn
        } else {
            left = mid + 1; // Tăng giới hạn dưới
        }
    }

    // Ghi kết quả ra file output
    outputFile << result << endl;
    outputFile.close();

    return 0;
}
