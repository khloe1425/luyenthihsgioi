#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream inputFile("FIND.INP");  // Mở file đầu vào
    ofstream outputFile("FIND.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> segments[i].first >> segments[i].second;
        if (segments[i].first > segments[i].second) {
            swap(segments[i].first, segments[i].second); // Đảm bảo đoạn thẳng luôn có dạng (x, y) với x <= y
        }
    }

    // Sắp xếp các đoạn thẳng theo điểm đầu, nếu trùng thì theo điểm cuối
    sort(segments.begin(), segments.end());

    // Xác định độ dài phủ lớn nhất
    int currentStart = segments[0].first, currentEnd = segments[0].second;
    long long totalLength = 0;

    for (int i = 1; i < n; ++i) {
        if (segments[i].first <= currentEnd) {
            // Nếu đoạn mới chồng lấn, mở rộng đoạn hiện tại
            currentEnd = max(currentEnd, segments[i].second);
        } else {
            // Nếu không chồng lấn, cộng độ dài đoạn hiện tại vào tổng
            totalLength += currentEnd - currentStart;
            currentStart = segments[i].first;
            currentEnd = segments[i].second;
        }
    }

    // Cộng đoạn cuối cùng
    totalLength += currentEnd - currentStart;

    outputFile << totalLength << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
