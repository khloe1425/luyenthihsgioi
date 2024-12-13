#include <iostream>
#include <fstream>

using namespace std;

// Hàm kiểm tra xem số num có hợp lệ không
bool isValidNumber(int num) {
    int sum = 0, count = 0, temp = num;

    // Tính tổng các chữ số và số chữ số
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
        count++;
    }

    // Kiểm tra tổng các chữ số chia hết cho số chữ số
    return (sum % count == 0);
}

// Hàm tìm số thứ k trong dãy
int findKthDivnNumber(int k) {
    int count = 0;
    int num = 1;

    while (true) {
        if (isValidNumber(num)) {
            count++;
            if (count == k) {
                return num;
            }
        }
        num++;
    }
}

int main() {
    // Mở file input và output
    ifstream inputFile("DIVN.inp");
    ofstream outputFile("DIVN.out");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int k;
    inputFile >> k;  // Đọc giá trị k từ file input

    int result = findKthDivnNumber(k);  // Tìm số thứ k

    outputFile << result << endl;  // Ghi kết quả ra file output

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
