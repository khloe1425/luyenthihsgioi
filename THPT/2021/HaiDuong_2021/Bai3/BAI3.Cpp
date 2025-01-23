#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int main() {
    ifstream inputFile("BAI3.INP");  // Mở file đầu vào
    ofstream outputFile("BAI3.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    unordered_map<int, int> itemCount; // Bản đồ lưu mã số mặt hàng và số lượng
    int code;
    int maxCount = 0;
    int maxItem = 0;

    while (inputFile >> code && code != 0) {
        itemCount[code]++; // Đếm số lượng mỗi mặt hàng
        if (itemCount[code] > maxCount || (itemCount[code] == maxCount && code < maxItem)) {
            maxCount = itemCount[code];
            maxItem = code;
        }
    }

    outputFile << maxItem << " " << maxCount << endl; // Ghi kết quả vào file

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
