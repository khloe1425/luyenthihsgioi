#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;

// Hàm tính số phép toán tối thiểu để biến đổi A thành 0
int minOperations(long long A, long long B) {
    int minSteps = INT_MAX;

    // Nếu B ban đầu là 1, phải tăng B trước
    if (B == 1) {
        B++;
        minSteps = 1; // Đếm bước tăng B đầu tiên
    }

    // Thử tăng B từ giá trị hiện tại
    for (int k = 0; k <= 50; k++) { // Giới hạn số lần tăng B để đảm bảo hiệu suất
        long long currentB = B + k;
        int steps = k; // Số lần tăng B
        long long currentA = A;

        // Chia liên tục cho đến khi A = 0
        while (currentA > 0) {
            currentA /= currentB;
            steps++;
        }

        // Cập nhật kết quả tối thiểu
        minSteps = min(minSteps, steps);
    }

    return minSteps;
}

int main() {
    ifstream inputFile("BIENDOISO.INP");
    ofstream outputFile("BIENDOISO.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    int T;
    inputFile >> T;

    while (T--) {
        long long A, B;
        inputFile >> A >> B;

        int result = minOperations(A, B);
        outputFile << result << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
