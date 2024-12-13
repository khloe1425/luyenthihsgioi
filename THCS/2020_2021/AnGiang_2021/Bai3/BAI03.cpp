#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Mở file input và output
    ifstream inputFile("BAI03.INP");
    ofstream outputFile("BAI03.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    // Đọc số tiền cần rút
    long long amount;
    inputFile >> amount;

    // Kiểm tra số tiền có hợp lệ không
    if (amount < 10000 || amount % 10000 != 0) {
        outputFile << "KHONG THUC HIEN DUOC" << endl;
        return 0;
    }

    // Các mệnh giá tiền
    vector<int> denominations = {500000, 200000, 100000, 50000, 20000, 10000};
    vector<int> count(denominations.size(), 0);

    // Tính số tờ tiền
    long long totalNotes = 0;
    for (size_t i = 0; i < denominations.size(); ++i) {
        if (amount >= denominations[i]) {
            count[i] = amount / denominations[i]; // Số tờ của mệnh giá hiện tại
            amount %= denominations[i];          // Cập nhật số tiền còn lại
            totalNotes += count[i];              // Cộng tổng số tờ
        }
    }

    // Kiểm tra nếu không rút được số tiền
    if (amount > 0) {
        outputFile << "KHONG THUC HIEN DUOC" << endl;
    } else {
        // Ghi kết quả ra file
        outputFile << totalNotes << endl;
        for (int i = count.size() - 1; i >= 0; --i) { // In từ mệnh giá nhỏ đến lớn
            outputFile << count[i] << " ";
        }
        outputFile << endl;
    }

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
