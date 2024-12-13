#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int main() {
    // Mở file input và output
    ifstream inputFile("SQUARE.INP");
    ofstream outputFile("SQUARE.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    // Đếm số lượng thanh gỗ cho mỗi độ dài
    unordered_map<int, int> count;
    for (int i = 0; i < n; ++i) {
        int length;
        inputFile >> length;
        count[length]++;
    }

    // Tìm diện tích lớn nhất và số lượng hình vuông
    int maxArea = -1; // Nếu không tạo được hình vuông nào
    int totalSquares = 0;

    for (const auto& [length, numSticks] : count) {
        int squares = numSticks / 4; // Số hình vuông có thể tạo
        if (squares > 0) {
            int area = length * length;
            if (area > maxArea) {
                maxArea = area;
                totalSquares = squares;
            } else if (area == maxArea) {
                totalSquares += squares; // Nếu diện tích bằng nhau, cộng dồn số lượng
            }
        }
    }

    // Ghi kết quả ra file
    if (maxArea == -1) {
        outputFile << -1 << endl; // Không tạo được hình vuông nào
    } else {
        outputFile << maxArea << " " << totalSquares << endl;
    }

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
