            #include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line {
    int start, end;
};

// Hàm so sánh để sắp xếp các đoạn
bool compare(Line a, Line b) {
    if (a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
}

int main() {
    ifstream input("CABCAR.INP");
    ofstream output("CABCAR.OUT");

    int n;
    input >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        input >> p[i];
    }

    // Tạo danh sách các đoạn thẳng
    vector<Line> lines;
    for (int i = 1; i <= n; ++i) {
        lines.push_back({i, p[i]});
    }

    // Sắp xếp các đoạn theo điểm xuất phát, rồi điểm kết thúc
    sort(lines.begin(), lines.end(), compare);

    // Sử dụng tham lam để chọn các đoạn không giao nhau
    int count = 0;
    int lastEnd = 0;

    for (const auto &line : lines) {
        if (line.start > lastEnd) {
            count++;
            lastEnd = line.end;
        }
    }

    // Ghi kết quả
    output << count << endl;

    input.close();
    output.close();

    return 0;
}
