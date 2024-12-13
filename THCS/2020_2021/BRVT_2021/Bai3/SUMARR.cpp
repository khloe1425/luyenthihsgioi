#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Mở file input và output
    ifstream inputFile("SUMARR.INP");
    ofstream outputFile("SUMARR.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    // Đọc số phần tử và dãy số
    int n;
    inputFile >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> arr[i];
    }

    // Biến đếm số lượng dãy con có tổng chẵn
    int countEven = 0;

    // Duyệt qua tất cả dãy con (sử dụng bitmask)
    for (int mask = 1; mask < (1 << n); ++mask) { // mask = 1 để loại bỏ dãy con rỗng
        int sum = 0;
        bool valid = false; // Kiểm tra có ít nhất một phần tử trong dãy con
        for (int i = 0; i < n; ++i) {
            // Nếu bit thứ i trong mask bật, thêm phần tử arr[i] vào dãy con
            if (mask & (1 << i)) {
                sum += arr[i];
                valid = true;
            }
        }
        // Chỉ đếm dãy con có ít nhất một phần tử và tổng chẵn
        if (valid && sum % 2 == 0) {
            countEven++;
        }
    }

    // Ghi kết quả ra file
    outputFile << countEven << endl;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
