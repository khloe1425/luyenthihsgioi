#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int x, y1, y2, type; // x là tọa độ, y1 và y2 là khoảng y, type là loại sự kiện (1: mở, -1: đóng)
    bool operator<(const Event &other) const {
        return x < other.x;
    }
};

int main() {
    ifstream inputFile("BAI5.INP");
    ofstream outputFile("BAI5.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    vector<Event> events;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        inputFile >> x1 >> y1 >> x2 >> y2;

        // Đảm bảo tọa độ đúng
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        // Thêm sự kiện mở và đóng
        events.push_back({x1, y1, y2, 1});
        events.push_back({x2, y1, y2, -1});
    }

    // Sắp xếp sự kiện theo tọa độ x
    sort(events.begin(), events.end());

    long long totalArea = 0;
    vector<pair<int, int>> active; // Danh sách các đoạn y đang mở
    int prevX = events[0].x;

    for (const auto &e : events) {
        int currX = e.x;

        // Tính diện tích theo khoảng y hiện tại
        if (!active.empty()) {
            int totalY = 0;
            int prevY = -1;
            for (const auto &segment : active) {
                totalY += max(0, segment.second - max(prevY, segment.first));
                prevY = max(prevY, segment.second);
            }
            totalArea += 1LL * totalY * (currX - prevX);
        }

        // Cập nhật danh sách đoạn y đang mở
        if (e.type == 1) {
            active.push_back({e.y1, e.y2});
            sort(active.begin(), active.end());
        } else {
            active.erase(remove(active.begin(), active.end(), make_pair(e.y1, e.y2)), active.end());
        }

        prevX = currX;
    }

    outputFile << totalArea << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
