#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <climits>
using namespace std;

struct Building {
    int x1, y1, x2, y2, height; // Tọa độ và chiều cao của tòa nhà
};

// Kiểm tra hai tòa nhà có lối đi độc đạo hay không
bool hasCommonEdge(const Building &a, const Building &b) {
    // Kiểm tra cạnh chung theo trục x (cạnh dọc)
    if ((a.y1 == b.y2 || a.y2 == b.y1) && !(a.x2 < b.x1 || b.x2 < a.x1)) {
        return true;
    }
    // Kiểm tra cạnh chung theo trục y (cạnh ngang)
    if ((a.x1 == b.x2 || a.x2 == b.x1) && !(a.y2 < b.y1 || b.y2 < a.y1)) {
        return true;
    }
    return false;
}

int main() {
    // Đọc dữ liệu từ file
    ifstream inputFile("BUILDING.INP");
    ofstream outputFile("BUILDING.OUT");

    int n;
    inputFile >> n;

    vector<Building> buildings(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> buildings[i].x1 >> buildings[i].y1 >> buildings[i].x2 >> buildings[i].y2 >> buildings[i].height;
    }

    // Tìm khoảng chênh lệch nhỏ nhất
    int minDifference = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (hasCommonEdge(buildings[i], buildings[j])) {
                int diff = abs(buildings[i].height - buildings[j].height);
                minDifference = min(minDifference, diff);
                found = true;
            }
        }
    }

    // Ghi kết quả ra file
    if (found) {
        outputFile << minDifference << endl;
    } else {
        outputFile << -1 << endl;
    }

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
